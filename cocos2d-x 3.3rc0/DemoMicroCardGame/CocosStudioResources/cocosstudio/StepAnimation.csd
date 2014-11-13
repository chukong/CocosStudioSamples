<GameProjectFile>
  <PropertyGroup Type="Node" Name="StepAnimation" ID="8245da65-ba35-4915-bcc9-571b2b7a709e" Version="2.0.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="600" Speed="1">
        <Timeline ActionTag="1073032531" FrameType="PositionFrame">
          <PointFrame FrameIndex="0" X="0" Y="0" />
        </Timeline>
        <Timeline ActionTag="1073032531" FrameType="ScaleFrame">
          <PointFrame FrameIndex="0" X="1" Y="1" />
          <PointFrame FrameIndex="30" X="1" Y="1" />
          <PointFrame FrameIndex="350" X="1" Y="1" />
          <PointFrame FrameIndex="375" X="1" Y="1" />
          <PointFrame FrameIndex="600" X="1" Y="1" />
        </Timeline>
        <Timeline ActionTag="1073032531" FrameType="RotationSkewFrame">
          <PointFrame FrameIndex="0" X="0" Y="0" />
          <PointFrame FrameIndex="30" X="0" Y="0" />
          <PointFrame FrameIndex="350" X="0" Y="0" />
          <PointFrame FrameIndex="375" X="0" Y="0" />
          <PointFrame FrameIndex="600" X="0" Y="0" />
        </Timeline>
        <Timeline ActionTag="1073032531" FrameType="ColorFrame">
          <ColorFrame FrameIndex="0" Alpha="0">
            <Color A="255" R="255" G="255" B="255" />
          </ColorFrame>
          <ColorFrame FrameIndex="30" Alpha="255">
            <Color A="255" R="255" G="255" B="255" />
          </ColorFrame>
          <ColorFrame FrameIndex="350" Alpha="255">
            <Color A="255" R="255" G="255" B="255" />
          </ColorFrame>
          <ColorFrame FrameIndex="375" Alpha="0">
            <Color A="255" R="255" G="255" B="255" />
          </ColorFrame>
          <ColorFrame FrameIndex="600" Alpha="0">
            <Color A="255" R="255" G="255" B="255" />
          </ColorFrame>
        </Timeline>
        <Timeline ActionTag="1073032531" FrameType="EventFrame">
          <StringFrame FrameIndex="30" Value="hide_point" />
          <StringFrame FrameIndex="350" Value="show_point" />
        </Timeline>
      </Animation>
      <ObjectData Name="Node" CanEdit="False" FrameEvent="" ctype="SingleNodeObjectData">
        <Position X="0" Y="0" />
        <Scale ScaleX="1" ScaleY="1" />
        <AnchorPoint />
        <CColor A="255" R="255" G="255" B="255" />
        <Size X="0" Y="0" />
        <PrePosition X="0" Y="0" />
        <PreSize X="0" Y="0" />
        <Children>
          <NodeObjectData Name="Sprite_1" ActionTag="1073032531" FrameEvent="show_point" Tag="317" ObjectIndex="1" ctype="SpriteObjectData">
            <Position X="0" Y="0" />
            <Scale ScaleX="1" ScaleY="1" />
            <AnchorPoint ScaleX="0.2421885" ScaleY="0.703125" />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="64" Y="64" />
            <PrePosition X="0" Y="0" />
            <PreSize X="0" Y="0" />
            <FileData Type="Normal" Path="MissionSelect/foot.png" />
          </NodeObjectData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>