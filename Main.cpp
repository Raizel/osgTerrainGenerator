/*
	Terrain Generator with Box Filter(With smoothing). Version 1.0.
	Based on tutorial:
	http://archive.gamedev.net/archive/reference/articles/article2164.html


	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.
*/


#include "osg_all.hpp" //All OSG headers in one file(very comfortably)!



using namespace std;


class Log : public osg::NotifyHandler
{
public:
	Log();
	~Log();

	void notify(osg::NotifySeverity severity, const char* msg);


protected:
	ofstream _log;

};

Log::Log()
{
	_log.open("osgTerrainGenerator.log");
}

Log::~Log()
{
	_log.close();
}

void Log::notify(osg::NotifySeverity severity, const char* msg)
{
	_log << msg;
}


osg::ref_ptr<osg::FloatArray> TerrainFilter(unsigned int width, unsigned int height, osg::FloatArray* heightMap, bool smoothEdges = false)
{
	//     width: Width of the height map in bytes
	//    height: Height of the height map in bytes
	// heightMap: Pointer to your height map data
	// Temporary values for traversing single dimensional arrays

	long x = 0;
	long y = 0;

	long  widthClamp = (smoothEdges) ?  width : width  - 1;
	long heightClamp = (smoothEdges) ? height : height - 1;

	// [Optimization] Calculate bounds ahead of time
	unsigned int bounds = width * height;

	// Validate requirements
	if (!heightMap)
	return 0;

	// Allocate the result
	osg::ref_ptr<osg::FloatArray> result = new osg::FloatArray(bounds);

	// Make sure memory was allocated
	if (!result)
	return 0;

	for(y = (smoothEdges) ? 0 : 1; y < heightClamp; ++y)
	{
		for (x = (smoothEdges) ? 0 : 1; x < widthClamp; ++x)
		{
			// Sample a 3x3 filtering grid based on surrounding neighbors
			float value = 0.0f;
			float cellAverage = 1.0f;

			// Sample top row
			if (((x - 1) + (y - 1) * width) >= 0 && ((x - 1) + (y - 1) * width) < bounds)
			{
				value += (*heightMap)[(x - 1) + (y - 1) * width];
				++cellAverage;
			}

			if (((x - 0) + (y - 1) * width) >= 0 && ((x - 0) + (y - 1) * width) < bounds)
			{
				value += (*heightMap)[(x    ) + (y - 1) * width];
				++cellAverage;
			}

			if (((x + 1) + (y - 1) * width) >= 0 && ((x + 1) + (y - 1) * width) < bounds)
			{
				value += (*heightMap)[(x + 1) + (y - 1) * width];
				++cellAverage;
			}

			// Sample middle row

			if (((x - 1) + (y - 0) * width) >= 0 && ((x - 1) + (y - 0) * width) < bounds)
			{
				value += (*heightMap)[(x - 1) + y * width];
				++cellAverage;
			}

      
			// Sample center point (will always be in bounds)
			value += (*heightMap)[x + y * width];

			if (((x + 1) + (y - 0) * width) >= 0 && ((x + 1) + (y - 0) * width) < bounds)
			{
				value += (*heightMap)[(x + 1) + y * width];
				++cellAverage;
			}

			// Sample bottom row      
			if (((x - 1) + (y + 1) * width) >= 0 && ((x - 1) + (y + 1) * width) < bounds)
			{
				value += (*heightMap)[(x - 1) + (y + 1) * width];
				++cellAverage;
			}

			if (((x - 0) + (y + 1) * width) >= 0 && ((x - 0) + (y + 1) * width) < bounds)
			{
				value += (*heightMap)[(x    ) + (y + 1) * width];
				++cellAverage;
			}

			if (((x + 1) + (y + 1) * width) >= 0 && ((x + 1) + (y + 1) * width) < bounds)
			{
				value += (*heightMap)[(x + 1) + (y + 1) * width];
				++cellAverage;
			}

			// Store the result
			(*result)[x + y * width] = value / cellAverage;

		}
	}

	return result.release();
}


class NormalSmoother : public osg::NodeVisitor
{
public:
	NormalSmoother() : NodeVisitor(NodeVisitor::TRAVERSE_ALL_CHILDREN), smt(new osgUtil::SmoothingVisitor)
	{
	}

    virtual void apply(osg::Geode& geode)
    {
        for (unsigned int i = 0; i < geode.getNumDrawables(); ++i)
        {
            osg::Geometry *geo = dynamic_cast<osg::Geometry *>(geode.getDrawable(i));
            if (geo != NULL)
            {
				smt->smooth(*geo, osg::DegreesToRadians(76.0));
            }
        }
        traverse(geode);
    }
private:
	osg::ref_ptr<osgUtil::SmoothingVisitor> smt;

};


int main(int argc, char* argv[])
{
	osg::setNotifyLevel(osg::INFO);
	osg::setNotifyHandler(new Log());


	osg::ref_ptr<osg::Group> root = new osg::Group;

    osg::ref_ptr<osg::Geode> geode;
	osg::ref_ptr<osg::HeightField> height_field;
	osg::ref_ptr<osg::LOD> lod;

	osg::ref_ptr<osg::Image> height_map;
	std::vector< osg::ref_ptr<osg::FloatArray> > heights_vec;
	osg::ref_ptr<osg::FloatArray> data;


	height_map = osgDB::readImageFile("terrain_height.tif");
	if(!height_map.valid())
	{
		cout << "Can't find image heightmap. Make sure to file exist." << endl;
	}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////

	/*
		X side vertices number. Get from heightmap.
	*/
	unsigned int columns = height_map->s();

	/*
		Y side vertices number. Get from heightmap.
	*/
	unsigned int rows = height_map->t();

	/*
		terrain max height
	*/
	const float terrain_height = 12.0f;

	/*
		number of segments of terrain, for example 8x8.
	*/
	const unsigned int cell_side_num = 8;

	/*
		LOD number. Settings number of LOD cells.
	*/
	const unsigned int lod_num = 4;

	/*
		LOD visible range.
	*/
	float visible_range = 250.0f;

	/*
		osg::HeightField intervals.
		Set size of terrain(NOT columns or rows!).
		If set 1.0f and heightmap size 1024x1024,
		terrain size 1024x1024, if 0.5f, 512x512, etc.
		If value is less, less width and length, and more detailed terrain.
	*/
	float XInterval = 1.0f;
	float YInterval = 1.0f;

//////////////////////////////////////////////////////////////////////////////////////////////////////

	unsigned int vertices_num = columns * rows;

	const unsigned int cell_count = cell_side_num * cell_side_num;
	const unsigned int cell_size = columns / cell_side_num;


	double pos_x;
	double pos_y;
	
	unsigned int cell_size_scaled = 0;

	float range_a = 0.0f;
	float range_b = visible_range;

	unsigned int tex_size = 0;
	unsigned int pos_z = 0;

////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

    osg::Texture2D* tex = new osg::Texture2D(osgDB::readImageFile("terrain_diffuse.tif"));
    tex->setFilter(osg::Texture2D::MIN_FILTER,osg::Texture2D::LINEAR_MIPMAP_LINEAR);
    tex->setFilter(osg::Texture2D::MAG_FILTER,osg::Texture2D::LINEAR);
	tex->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP_TO_BORDER);
    tex->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::CLAMP_TO_BORDER);

/*
    osg::Texture2D* ntex = new osg::Texture2D(osgDB::readImageFile("terrain_normals.tif"));
    ntex->setFilter(osg::Texture2D::MIN_FILTER,osg::Texture2D::LINEAR_MIPMAP_LINEAR);
    ntex->setFilter(osg::Texture2D::MAG_FILTER,osg::Texture2D::LINEAR);
	ntex->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP_TO_BORDER);
    ntex->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::CLAMP_TO_BORDER);
*/
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

	double scale = 1.0 / double(cell_side_num);

	osg::ref_ptr<osg::TexMat> tex_mat;
	osg::ref_ptr<osg::StateSet> terrain_stateset;

	cout << "Creating height array... " << endl;


	for(unsigned int s = lod_num; s != 0; --s)
	{
		tex_size = ((columns / lod_num) * s) + 1;

		height_map->scaleImage(tex_size, tex_size, 1);

		data = new osg::FloatArray(osg::Array::BIND_PER_VERTEX, (tex_size*tex_size));

		for(unsigned int j = 0; j < tex_size; ++j)
		{
			for(unsigned int i = 0; i < tex_size; ++i)
			{
				(*data)[i * tex_size + j] = ((float(*height_map->data(i, j)) / 256.0f) * terrain_height);
			}
		}
	
		heights_vec.push_back(TerrainFilter(tex_size, tex_size, data, false));
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	cout << "Creating terrain... " << endl;

	for(unsigned int j = 0; j < cell_side_num; ++j)
	{
		for(unsigned int i = 0; i < cell_side_num; ++i)
		{
			lod = new osg::LOD;
			
			for(unsigned int l = lod_num, k = 0; l != 0, k < lod_num; --l, ++k)
			{
				cell_size_scaled = ((cell_size / lod_num) * l + 1);

				pos_x = double(i) * double(cell_size);
				pos_y = double(j) * double(cell_size);

				height_field = new osg::HeightField;
				height_field->allocate(cell_size_scaled, cell_size_scaled); //
				
				height_field->setXInterval(XInterval * float(float(cell_size) / float(cell_size_scaled - 1.0f)));
				height_field->setYInterval(YInterval * float(float(cell_size) / float(cell_size_scaled - 1.0f)));

				height_field->setSkirtHeight(float(columns / 200.0f) * XInterval);
				

				height_field->setOrigin(osg::Vec3((pos_x * double(XInterval)) - (double(columns) / 2.0) * double(XInterval), (pos_y * double(YInterval)) - (double(rows) / 2.0) * double(XInterval), 0.0));


				for(unsigned int yy = 0; yy < cell_size_scaled; ++yy)
				{
					for(unsigned int xx = 0; xx < cell_size_scaled; ++xx)
					{
						tex_size = ((columns / lod_num) * l) + 1;

						pos_z = (i * (cell_size_scaled - 1) + xx) * tex_size + (j * (cell_size_scaled - 1) + yy);
						height_field->setHeight(xx, yy, heights_vec[k]->at(pos_z));
					}
				}



				geode = new osg::Geode;
				geode->addDrawable(new osg::ShapeDrawable(height_field.get()));

				tex_mat = new osg::TexMat;
				//terrain_stateset = new osg::StateSet;

				tex_mat->setMatrix(osg::Matrix::translate((pos_x / double(columns) * double(cell_side_num)), (pos_y / double(rows) * double(cell_side_num)), 0.0) * osg::Matrix::scale(scale,scale,1.0));

				geode->getOrCreateStateSet()->setTextureAttributeAndModes(0, tex);
				geode->getOrCreateStateSet()->setTextureAttributeAndModes(0, tex_mat.get());
				
/*
				terrain_stateset->setTextureAttributeAndModes(1, ntex);
				terrain_stateset->setTextureAttributeAndModes(1, tex_mat.get());
*/
				//geode->setStateSet(terrain_stateset.get());

/*
				NormalSmoother smoother;
				geode->accept(smoother);
*/
				if(l == 1)
				{
					lod->addChild(geode.get(), range_a, FLT_MAX);
				}
				else
				{
					lod->addChild(geode.get(), range_a, range_b);
				}
				range_a += visible_range;
				range_b += visible_range;
			}


			root->addChild(lod.get());
			range_a = 0.0f;
			range_b = visible_range;
		}
	}


	cout << "Writing root..." << endl;
	osgDB::writeNodeFile(*root.get(), "terrain.osgb");


    osgViewer::Viewer viewer;

	viewer.getCamera()->setProjectionMatrixAsPerspective (67.5f, static_cast<double>(1920)/static_cast<double>(1080), 0.1, 1000000.0);
	

    viewer.addEventHandler(new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()));
    viewer.addEventHandler(new osgViewer::ThreadingHandler);
    viewer.addEventHandler(new osgViewer::WindowSizeHandler);

	osg::ref_ptr<osgViewer::StatsHandler> stats = new osgViewer::StatsHandler;
	viewer.addEventHandler(stats.get());


    viewer.addEventHandler(new osgViewer::RecordCameraPathHandler);
    viewer.addEventHandler(new osgViewer::LODScaleHandler);
    viewer.addEventHandler(new osgViewer::ScreenCaptureHandler);

    viewer.setSceneData(root.get());


	return viewer.run();
}

