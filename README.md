CocoStudioSamples
=================

This are the samples for CocoStudio

Setup
--------------
  - cd CocoStudioSamples
  - git submodule update --init (This will checkout cocos2d-x 2.2.1)


How-tos
--------------

Sample for CocosStudio 1.1 + Cocos2d-x 2.2.1

  - DemoCowboyGame: a simple game using Animation, UI and Scene together. 
    - On Windows, install CocoStudio 1.1: http://www.cocos2d-x.org/download
      - cd NewCowboyDemo/EditorProjects/DemoScene
      - Double click DemoPlayer.xml to edit the animation, then export the project to override Resources/DemoPlayer
      - Double click DemoHead_UI.xml to edit the hud, then export the project to override Resources/DemoHead_UI
      - Double click DemoCowboy.xml. You should see the updated animation and hud since they are loaded from Resources folder. Export the project to override NewCowboyDemo/EditorProjects/DemoScene/Export
    - On Mac, open NewCowboyDemo/SourceCode/proj.ios/CowboyScene.xcodeproj
      - The scene from CocoStudio are included as folder references under SceneResources group
      - Clean and run. You should see the new updates. 


Old samples for CocoStudio 1.0.x + Cocos2d-x 2.1.x

  - First you need to switch back to Cocos2d-x 2.1.x
    - cd cocos2d-x
    - git checkout tags/cocos2d-x-2.1.5
  - DemoBag: Inventory UI Demo
  - DemoFishingJoy: Main Menu UI Demo
  - DemoGame: Simple Demo game with physics enabled
  - DemoGameScene:	Game Scene Demo
  - DemoLogin: TextInput Demo
  - DemoMap: Map UI Demo
  - DemoShop: Shop UI Demo
  - SampleChangeEquip: Avatar system Demo
  - SampleCollision: Collision Detection Demo
  - SampleFlashImport: Flash animation Import Demo
  - SampleFrameAnimation: Frame Animation Demo
  - SampleHelloUI: UI event Demo
  - SampleImageViewer: ImageView Switch page Demo
  - SampleKeyFrameAnimation: KeyFrameAnimation Demo
  - SampleParticle: Particle Demo
  - SampleSceneEditor: Game Scene Demo
  - SampleUIAnimation: UI Animation Demo


