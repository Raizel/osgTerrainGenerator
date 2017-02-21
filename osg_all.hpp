#pragma once
#ifndef _OSG_ALL_HPP_
#define _OSG_ALL_HPP_

///list of all  openscenegraph headers

//OpenThreads
#include <OpenThreads/Atomic>
#include <OpenThreads/Barrier>
#include <OpenThreads/Block>
#include <OpenThreads/Condition>
#include <OpenThreads/Config>
#include <OpenThreads/Mutex>
#include <OpenThreads/ReadWriteMutex>
#include <OpenThreads/ReentrantMutex>
#include <OpenThreads/ScopedLock>
#include <OpenThreads/Thread>


//osg
#include <osg/AlphaFunc>
#include <osg/AnimationPath>
#include <osg/ApplicationUsage>
#include <osg/ArgumentParser>
#include <osg/Array>
#include <osg/ArrayDispatchers>
#include <osg/AudioStream>
#include <osg/AutoTransform>
#include <osg/Billboard>
#include <osg/BlendColor>
#include <osg/BlendEquation>
#include <osg/BlendEquationi>
#include <osg/BlendFunc>
#include <osg/BlendFunci>
#include <osg/BoundingBox>
#include <osg/BoundingSphere>
#include <osg/BoundsChecking>
#include <osg/buffered_value>
#include <osg/BufferIndexBinding>
#include <osg/BufferObject>
#include <osg/BufferTemplate>
#include <osg/Callback>
#include <osg/Camera>
#include <osg/CameraView>
#include <osg/Capability>
#include <osg/ClampColor>
#include <osg/ClearNode>
#include <osg/ClipControl>
#include <osg/ClipNode>
#include <osg/ClipPlane>
#include <osg/ClusterCullingCallback>
#include <osg/CollectOccludersVisitor>
#include <osg/ColorMask>
#include <osg/ColorMaski>
#include <osg/ColorMatrix>
#include <osg/ComputeBoundsVisitor>
#include <osg/Config>
#include <osg/ConvexPlanarOccluder>
#include <osg/ConvexPlanarPolygon>
#include <osg/CoordinateSystemNode>
#include <osg/CopyOp>
#include <osg/CullFace>
#include <osg/CullingSet>
#include <osg/CullSettings>
#include <osg/CullStack>
#include <osg/DeleteHandler>
#include <osg/Depth>
#include <osg/DisplaySettings>
#include <osg/Drawable>
#include <osg/DrawPixels>
#include <osg/Endian>
#include <osg/fast_back_stack>
#include <osg/Fog>
#include <osg/FragmentProgram>
#include <osg/FrameBufferObject>
#include <osg/FrameStamp>
#include <osg/FrontFace>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/GL>
#include <osg/GL2Extensions>
#include <osg/GLBeginEndAdapter>
#include <osg/GLDefines>
#include <osg/GLExtensions>
#include <osg/GLObjects>
//#include <osg/GLU>	//Perhaps, don't need include this? Problem with CEGUI!
#include <osg/GraphicsContext>
#include <osg/GraphicsCostEstimator>
#include <osg/GraphicsThread>
#include <osg/Group>
#include <osg/Hint>
#include <osg/Image>
#include <osg/ImageSequence>
#include <osg/ImageStream>
#include <osg/ImageUtils>
#include <osg/io_utils>
#include <osg/KdTree>
#include <osg/Light>
#include <osg/LightModel>
#include <osg/LightSource>
#include <osg/LineSegment>
#include <osg/LineStipple>
#include <osg/LineWidth>
#include <osg/LOD>
#include <osg/LogicOp>
#include <osg/Material>
#include <osg/Math>
#include <osg/Matrix>
#include <osg/Matrixd>
#include <osg/Matrixf>
#include <osg/MatrixTransform>
#include <osg/MixinVector>
#include <osg/Multisample>
#include <osg/Node>
#include <osg/NodeCallback>
#include <osg/NodeTrackerCallback>
#include <osg/NodeVisitor>
#include <osg/Notify>
#include <osg/Object>
#include <osg/Observer>
#include <osg/observer_ptr>
#include <osg/ObserverNodePath>
#include <osg/OccluderNode>
#include <osg/OcclusionQueryNode>
#include <osg/OperationThread>
#include <osg/PagedLOD>
#include <osg/PatchParameter>
#include <osg/Plane>
#include <osg/Point>
#include <osg/PointSprite>
#include <osg/PolygonMode>
#include <osg/PolygonOffset>
#include <osg/PolygonStipple>
#include <osg/Polytope>
#include <osg/PositionAttitudeTransform>
#include <osg/PrimitiveRestartIndex>
#include <osg/PrimitiveSet>
#include <osg/Program>
#include <osg/Projection>
#include <osg/ProxyNode>
#include <osg/Quat>
#include <osg/ref_ptr>
#include <osg/Referenced>
#include <osg/RenderInfo>
#include <osg/SampleMaski>
#include <osg/Scissor>
#include <osg/ScriptEngine>
#include <osg/Sequence>
#include <osg/ShadeModel>
#include <osg/Shader>
#include <osg/ShaderAttribute>
#include <osg/ShaderComposer>
#include <osg/ShadowVolumeOccluder>
#include <osg/Shape>
#include <osg/ShapeDrawable>
#include <osg/State>
#include <osg/StateAttribute>
#include <osg/StateAttributeCallback>
#include <osg/StateSet>
#include <osg/Stats>
#include <osg/Stencil>
#include <osg/StencilTwoSided>
#include <osg/Switch>
#include <osg/TemplatePrimitiveFunctor>
#include <osg/TexEnv>
#include <osg/TexEnvCombine>
#include <osg/TexEnvFilter>
#include <osg/TexGen>
#include <osg/TexGenNode>
#include <osg/TexMat>
#include <osg/Texture>
#include <osg/Texture1D>
#include <osg/Texture2D>
#include <osg/Texture2DArray>
#include <osg/Texture2DMultisample>
#include <osg/Texture3D>
#include <osg/TextureBuffer>
#include <osg/TextureCubeMap>
#include <osg/TextureRectangle>
#include <osg/Timer>
#include <osg/TransferFunction>
#include <osg/Transform>
#include <osg/TriangleFunctor>
#include <osg/TriangleIndexFunctor>
#include <osg/TriangleLinePointIndexFunctor>
#include <osg/Types>
#include <osg/Uniform>
#include <osg/UserDataContainer>
#include <osg/ValueObject>
#include <osg/Vec2>
#include <osg/Vec2b>
#include <osg/Vec2d>
#include <osg/Vec2f>
#include <osg/Vec2i>
#include <osg/Vec2s>
#include <osg/Vec2ub>
#include <osg/Vec2ui>
#include <osg/Vec2us>
#include <osg/Vec3>
#include <osg/Vec3b>
#include <osg/Vec3d>
#include <osg/Vec3f>
#include <osg/Vec3i>
#include <osg/Vec3s>
#include <osg/Vec3ub>
#include <osg/Vec3ui>
#include <osg/Vec3us>
#include <osg/Vec4>
#include <osg/Vec4b>
#include <osg/Vec4d>
#include <osg/Vec4f>
#include <osg/Vec4i>
#include <osg/Vec4s>
#include <osg/Vec4ub>
#include <osg/Vec4ui>
#include <osg/Vec4us>
#include <osg/VertexAttribDivisor>
#include <osg/VertexProgram>
#include <osg/View>
#include <osg/Viewport>


//osgAnimation
#include <osgAnimation/Action>
#include <osgAnimation/ActionAnimation>
#include <osgAnimation/ActionBlendIn>
#include <osgAnimation/ActionBlendOut>
#include <osgAnimation/ActionCallback>
#include <osgAnimation/ActionStripAnimation>
#include <osgAnimation/ActionVisitor>
#include <osgAnimation/Animation>
#include <osgAnimation/AnimationManagerBase>
#include <osgAnimation/AnimationUpdateCallback>
#include <osgAnimation/BasicAnimationManager>
#include <osgAnimation/Bone>
#include <osgAnimation/BoneMapVisitor>
#include <osgAnimation/Channel>
#include <osgAnimation/CubicBezier>
#include <osgAnimation/EaseMotion>
#include <osgAnimation/FrameAction>
#include <osgAnimation/Interpolator>
#include <osgAnimation/Keyframe>
#include <osgAnimation/LinkVisitor>
//#include <osgAnimation/MorphGeometry>
#include <osgAnimation/RigGeometry>
#include <osgAnimation/RigTransform>
#include <osgAnimation/RigTransformHardware>
#include <osgAnimation/RigTransformSoftware>
#include <osgAnimation/Sampler>
#include <osgAnimation/Skeleton>
#include <osgAnimation/StackedMatrixElement>
#include <osgAnimation/StackedQuaternionElement>
#include <osgAnimation/StackedRotateAxisElement>
#include <osgAnimation/StackedScaleElement>
#include <osgAnimation/StackedTransform>
#include <osgAnimation/StackedTransformElement>
#include <osgAnimation/StackedTranslateElement>
#include <osgAnimation/StatsHandler>
#include <osgAnimation/StatsVisitor>
#include <osgAnimation/Target>
#include <osgAnimation/Timeline>
#include <osgAnimation/TimelineAnimationManager>
#include <osgAnimation/UpdateBone>
#include <osgAnimation/UpdateMaterial>
#include <osgAnimation/UpdateMatrixTransform>
#include <osgAnimation/UpdateUniform>
#include <osgAnimation/Vec3Packed>
#include <osgAnimation/VertexInfluence>


//osgDB
#include <osgDB/Archive>
#include <osgDB/AuthenticationMap>
#include <osgDB/Callbacks>
#include <osgDB/ClassInterface>
#include <osgDB/ConvertBase64>
#include <osgDB/ConvertUTF>
#include <osgDB/DatabasePager>
#include <osgDB/DatabaseRevisions>
#include <osgDB/DataTypes>
#include <osgDB/DotOsgWrapper>
#include <osgDB/DynamicLibrary>
#include <osgDB/ExternalFileWriter>
#include <osgDB/FileCache>
#include <osgDB/FileNameUtils>
#include <osgDB/FileUtils>
#include <osgDB/fstream>
#include <osgDB/ImageOptions>
#include <osgDB/ImagePager>
#include <osgDB/ImageProcessor>
#include <osgDB/Input>
#include <osgDB/InputStream>
#include <osgDB/ObjectCache>
#include <osgDB/ObjectWrapper>
#include <osgDB/Options>
#include <osgDB/Output>
#include <osgDB/OutputStream>
#include <osgDB/ParameterOutput>
#include <osgDB/PluginQuery>
#include <osgDB/ReaderWriter>
#include <osgDB/ReadFile>
#include <osgDB/Registry>
#include <osgDB/Serializer>
#include <osgDB/SharedStateManager>
#include <osgDB/StreamOperator>
#include <osgDB/WriteFile>
#include <osgDB/XmlParser>


//osgFX
#include <osgFX/AnisotropicLighting>
#include <osgFX/BumpMapping>
#include <osgFX/Cartoon>
#include <osgFX/Effect>
#include <osgFX/MultiTextureControl>
#include <osgFX/Outline>
#include <osgFX/Registry>
#include <osgFX/Scribe>
#include <osgFX/SpecularHighlights>
#include <osgFX/Technique>
#include <osgFX/Validator>


//osgGA
#include <osgGA/AnimationPathManipulator>
#include <osgGA/CameraManipulator>
#include <osgGA/CameraViewSwitchManipulator>
#include <osgGA/Device>
#include <osgGA/DriveManipulator>
#include <osgGA/Event>
#include <osgGA/EventHandler>
#include <osgGA/EventQueue>
#include <osgGA/EventVisitor>
#include <osgGA/FirstPersonManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/GUIActionAdapter>
#include <osgGA/GUIEventAdapter>
#include <osgGA/GUIEventHandler>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/MultiTouchTrackballManipulator>
#include <osgGA/NodeTrackerManipulator>
#include <osgGA/OrbitManipulator>
#include <osgGA/SphericalManipulator>
#include <osgGA/StandardManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/TerrainManipulator>
#include <osgGA/TrackballManipulator>
#include <osgGA/UFOManipulator>
#include <osgGA/Widget>


//osgManipulator
#include <osgManipulator/AntiSquish>
#include <osgManipulator/Command>
#include <osgManipulator/CommandManager>
#include <osgManipulator/Constraint>
#include <osgManipulator/Dragger>
#include <osgManipulator/Projector>
#include <osgManipulator/RotateCylinderDragger>
#include <osgManipulator/RotateSphereDragger>
#include <osgManipulator/Scale1DDragger>
#include <osgManipulator/Scale2DDragger>
#include <osgManipulator/ScaleAxisDragger>
#include <osgManipulator/Selection>
#include <osgManipulator/TabBoxDragger>
#include <osgManipulator/TabBoxTrackballDragger>
#include <osgManipulator/TabPlaneDragger>
#include <osgManipulator/TabPlaneTrackballDragger>
#include <osgManipulator/TrackballDragger>
#include <osgManipulator/Translate1DDragger>
#include <osgManipulator/Translate2DDragger>
#include <osgManipulator/TranslateAxisDragger>
#include <osgManipulator/TranslatePlaneDragger>



//osgParticle
#include <osgParticle/AccelOperator>
#include <osgParticle/AngularAccelOperator>
#include <osgParticle/AngularDampingOperator>
#include <osgParticle/BounceOperator>
#include <osgParticle/BoxPlacer>
#include <osgParticle/CenteredPlacer>
#include <osgParticle/CompositePlacer>
#include <osgParticle/ConnectedParticleSystem>
#include <osgParticle/ConstantRateCounter>
#include <osgParticle/Counter>
#include <osgParticle/DampingOperator>
#include <osgParticle/DomainOperator>
#include <osgParticle/Emitter>
#include <osgParticle/ExplosionDebrisEffect>
#include <osgParticle/ExplosionEffect>
#include <osgParticle/ExplosionOperator>
#include <osgParticle/FireEffect>
#include <osgParticle/FluidFrictionOperator>
#include <osgParticle/FluidProgram>
#include <osgParticle/ForceOperator>
#include <osgParticle/Interpolator>
#include <osgParticle/LinearInterpolator>
#include <osgParticle/ModularEmitter>
#include <osgParticle/ModularProgram>
#include <osgParticle/MultiSegmentPlacer>
#include <osgParticle/Operator>
#include <osgParticle/OrbitOperator>
#include <osgParticle/Particle>
#include <osgParticle/ParticleEffect>
#include <osgParticle/ParticleProcessor>
#include <osgParticle/ParticleSystem>
#include <osgParticle/ParticleSystemUpdater>
#include <osgParticle/Placer>
#include <osgParticle/PointPlacer>
#include <osgParticle/PrecipitationEffect>
#include <osgParticle/Program>
#include <osgParticle/RadialShooter>
#include <osgParticle/RandomRateCounter>
#include <osgParticle/range>
#include <osgParticle/SectorPlacer>
#include <osgParticle/SegmentPlacer>
#include <osgParticle/Shooter>
#include <osgParticle/SinkOperator>
#include <osgParticle/SmokeEffect>
#include <osgParticle/SmokeTrailEffect>
#include <osgParticle/VariableRateCounter>


//osgPresentation
#include <osgPresentation/AnimationMaterial>
#include <osgPresentation/CompileSlideCallback>
#include <osgPresentation/Cursor>
#include <osgPresentation/KeyEventHandler>
#include <osgPresentation/PickEventHandler>
#include <osgPresentation/PropertyManager>
#include <osgPresentation/SlideEventHandler>
#include <osgPresentation/SlideShowConstructor>
#include <osgPresentation/Timeout>


/*
//osgQt
#include <osgQt/Export>
#include <osgQt/GraphicsWindowQt>
#include <osgQt/QFontImplementation>
#include <osgQt/QGraphicsViewAdapter>
#include <osgQt/QWebViewImage>
#include <osgQt/QWidgetImage>
#include <osgQt/Version>
*/

//osgShadow
#include <osgShadow/ConvexPolyhedron>
#include <osgShadow/DebugShadowMap>
#include <osgShadow/LightSpacePerspectiveShadowMap>
#include <osgShadow/MinimalCullBoundsShadowMap>
#include <osgShadow/MinimalDrawBoundsShadowMap>
#include <osgShadow/MinimalShadowMap>
#include <osgShadow/OccluderGeometry>
#include <osgShadow/ParallelSplitShadowMap>
#include <osgShadow/ProjectionShadowMap>
#include <osgShadow/ShadowedScene>
#include <osgShadow/ShadowMap>
#include <osgShadow/ShadowSettings>
#include <osgShadow/ShadowTechnique>
#include <osgShadow/ShadowTexture>
#include <osgShadow/ShadowVolume>
#include <osgShadow/SoftShadowMap>
#include <osgShadow/StandardShadowMap>
#include <osgShadow/ViewDependentShadowMap>
#include <osgShadow/ViewDependentShadowTechnique>


//osgSim
#include <osgSim/BlinkSequence>
#include <osgSim/ColorRange>
#include <osgSim/DOFTransform>
#include <osgSim/ElevationSlice>
#include <osgSim/GeographicLocation>
#include <osgSim/HeightAboveTerrain>
#include <osgSim/Impostor>
#include <osgSim/ImpostorSprite>
#include <osgSim/InsertImpostorsVisitor>
#include <osgSim/LightPoint>
#include <osgSim/LightPointNode>
#include <osgSim/LightPointSystem>
#include <osgSim/LineOfSight>
#include <osgSim/MultiSwitch>
#include <osgSim/ObjectRecordData>
#include <osgSim/OverlayNode>
#include <osgSim/ScalarBar>
#include <osgSim/ScalarsToColors>
#include <osgSim/Sector>
#include <osgSim/ShapeAttribute>
#include <osgSim/SphereSegment>
#include <osgSim/VisibilityGroup>


//osgTerrain
#include <osgTerrain/DisplacementMappingTechnique>
#include <osgTerrain/GeometryPool>
#include <osgTerrain/GeometryTechnique>
#include <osgTerrain/Layer>
#include <osgTerrain/Locator>
#include <osgTerrain/Terrain>
#include <osgTerrain/TerrainTechnique>
#include <osgTerrain/TerrainTile>
#include <osgTerrain/ValidDataOperator>


//osgText
#include <osgText/FadeText>
#include <osgText/Font>
#include <osgText/Font3D>
#include <osgText/Glyph>
#include <osgText/KerningType>
#include <osgText/String>
#include <osgText/Style>
#include <osgText/Text>
#include <osgText/Text3D>
#include <osgText/TextBase>

/*
//osgUI
#include <osgUI/AlignmentSettings>
#include <osgUI/Callbacks>
#include <osgUI/ColorPalette>
#include <osgUI/ComboBox>
#include <osgUI/Dialog>
#include <osgUI/FrameSettings>
#include <osgUI/Label>
#include <osgUI/LineEdit>
#include <osgUI/Popup>
#include <osgUI/PushButton>
#include <osgUI/Style>
#include <osgUI/TabWidget>
#include <osgUI/TextSettings>
#include <osgUI/Validator>
#include <osgUI/Widget>
*/

//osgUtil
#include <osgUtil/ConvertVec>
#include <osgUtil/CubeMapGenerator>
#include <osgUtil/CullVisitor>
#include <osgUtil/DelaunayTriangulator>
#include <osgUtil/DisplayRequirementsVisitor>
#include <osgUtil/DrawElementTypeSimplifier>
#include <osgUtil/EdgeCollector>
#include <osgUtil/GLObjectsVisitor>
#include <osgUtil/HalfWayMapGenerator>
#include <osgUtil/HighlightMapGenerator>
#include <osgUtil/IncrementalCompileOperation>
#include <osgUtil/IntersectionVisitor>
#include <osgUtil/IntersectVisitor>
#include <osgUtil/LineSegmentIntersector>
#include <osgUtil/MeshOptimizers>
#include <osgUtil/OperationArrayFunctor>
#include <osgUtil/Optimizer>
#include <osgUtil/PerlinNoise>
#include <osgUtil/PlaneIntersector>
#include <osgUtil/PolytopeIntersector>
#include <osgUtil/PositionalStateContainer>
#include <osgUtil/PrintVisitor>
#include <osgUtil/RayIntersector>
#include <osgUtil/ReflectionMapGenerator>
#include <osgUtil/RenderBin>
#include <osgUtil/RenderLeaf>
#include <osgUtil/RenderStage>
#include <osgUtil/ReversePrimitiveFunctor>
#include <osgUtil/SceneGraphBuilder>
#include <osgUtil/SceneView>
#include <osgUtil/ShaderGen>
#include <osgUtil/Simplifier>
#include <osgUtil/SmoothingVisitor>
#include <osgUtil/StateGraph>
#include <osgUtil/Statistics>
#include <osgUtil/TangentSpaceGenerator>
//#include <osgUtil/Tessellator>
#include <osgUtil/TransformAttributeFunctor>
#include <osgUtil/TransformCallback>
#include <osgUtil/TriStripVisitor>
#include <osgUtil/UpdateVisitor>


//osgViewer
#include <osgViewer/api/Win32/GraphicsHandleWin32>
#include <osgViewer/api/Win32/GraphicsWindowWin32>
#include <osgViewer/api/Win32/PixelBufferWin32>
#include <osgViewer/config/AcrossAllScreens>
#include <osgViewer/config/PanoramicSphericalDisplay>
#include <osgViewer/config/SingleScreen>
#include <osgViewer/config/SingleWindow>
#include <osgViewer/config/SphericalDisplay>
#include <osgViewer/config/WoWVxDisplay>
#include <osgViewer/CompositeViewer>
#include <osgViewer/GraphicsWindow>
#include <osgViewer/Keystone>
#include <osgViewer/Renderer>
#include <osgViewer/Scene>
#include <osgViewer/View>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerBase>
#include <osgViewer/ViewerEventHandlers>


//osgVolume
#include <osgVolume/FixedFunctionTechnique>
#include <osgVolume/Layer>
#include <osgVolume/Locator>
#include <osgVolume/MultipassTechnique>
#include <osgVolume/Property>
#include <osgVolume/RayTracedTechnique>
#include <osgVolume/Version>
#include <osgVolume/Volume>
#include <osgVolume/VolumeScene>
#include <osgVolume/VolumeSettings>
#include <osgVolume/VolumeTechnique>
#include <osgVolume/VolumeTile>


//osgWidget
#include <osgWidget/Box>
#include <osgWidget/Browser>
#include <osgWidget/Canvas>
#include <osgWidget/EventInterface>
#include <osgWidget/Frame>
#include <osgWidget/Input>
#include <osgWidget/Label>
#include <osgWidget/Lua>
#include <osgWidget/PdfReader>
#include <osgWidget/Python>
#include <osgWidget/ScriptEngine>
#include <osgWidget/StyleInterface>
#include <osgWidget/StyleManager>
#include <osgWidget/Table>
#include <osgWidget/Types>
#include <osgWidget/UIObjectParent>
#include <osgWidget/Util>
#include <osgWidget/ViewerEventHandlers>
#include <osgWidget/VncClient>
#include <osgWidget/Widget>
#include <osgWidget/Window>
#include <osgWidget/WindowManager>



#endif