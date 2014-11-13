<GameProjectFile>
  <PropertyGroup Type="Node" Name="Battle" ID="7def0ece-ff34-4ec8-b294-67f0a51a07d5" Version="2.0.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1" />
      <ObjectData Name="Node_1" CanEdit="False" Visible="False" FrameEvent="" ctype="SingleNodeObjectData">
        <Position X="0" Y="0" />
        <Scale ScaleX="1" ScaleY="1" />
        <AnchorPoint />
        <CColor A="255" R="255" G="255" B="255" />
        <Size X="0" Y="0" />
        <PrePosition X="0" Y="0" />
        <PreSize X="0" Y="0" />
        <Children>
          <NodeObjectData Name="Panel" ActionTag="-1" FrameEvent="" Tag="2" BackColorAlpha="0" ComboBoxIndex="1" ColorAngle="0" ctype="PanelObjectData">
            <Position X="5.356262" Y="-0.0007171631" />
            <Scale ScaleX="1" ScaleY="1" />
            <AnchorPoint />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="640" Y="960" />
            <PrePosition X="0" Y="0" />
            <PreSize X="0" Y="0" />
            <Children>
              <NodeObjectData Name="battle" ActionTag="31" ZOrder="2" FrameEvent="" Tag="13" TouchEnable="True" BackColorAlpha="0" ComboBoxIndex="1" ColorAngle="0" ctype="PanelObjectData">
                <Position X="0" Y="0" />
                <Scale ScaleX="1" ScaleY="1" />
                <AnchorPoint />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="640" Y="960" />
                <PrePosition X="0" Y="0" />
                <PreSize X="0" Y="0" />
                <Children>
                  <NodeObjectData Name="Map_Battlemap" ActionTag="498474463" FrameEvent="" Tag="170" ObjectIndex="1" ctype="GameMapObjectData">
                    <Position X="-6.213013" Y="177.3641" />
                    <Scale ScaleX="1" ScaleY="1" />
                    <AnchorPoint />
                    <CColor A="255" R="255" G="255" B="255" />
                    <Size X="640" Y="640" />
                    <PrePosition X="-0.009707833" Y="0.1847543" />
                    <PreSize X="0" Y="0" />
                    <FileData Type="Normal" Path="BattleScene/sandbg/sand.tmx" />
                  </NodeObjectData>
                </Children>
                <SingleColor A="255" R="0" G="0" B="0" />
                <FirstColor A="255" R="0" G="0" B="0" />
                <EndColor A="255" R="0" G="0" B="0" />
                <ColorVector ScaleX="1" ScaleY="-4.371139E-08" />
              </NodeObjectData>
            </Children>
            <SingleColor A="255" R="0" G="0" B="0" />
            <FirstColor A="255" R="0" G="0" B="0" />
            <EndColor A="255" R="0" G="0" B="0" />
            <ColorVector ScaleX="1" ScaleY="-4.371139E-08" />
          </NodeObjectData>
          <NodeObjectData Name="ProjectNode_Boss" ActionTag="247710649" FrameEvent="" Tag="4504" ObjectIndex="69" IconVisible="True" ctype="ProjectNodeObjectData">
            <Position X="198.5074" Y="297.4421" />
            <Scale ScaleX="1" ScaleY="1" />
            <AnchorPoint />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="0" Y="0" />
            <PrePosition X="0" Y="0" />
            <PreSize X="0" Y="0" />
            <Children>
              <NodeObjectData Name="Sprite_Bossbloodbg" ActionTag="467999760" FrameEvent="" Tag="70" ObjectIndex="5" ctype="SpriteObjectData">
                <Position X="-3.523682" Y="429.0418" />
                <Scale ScaleX="0.7921084" ScaleY="0.7991461" />
                <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="278" Y="53" />
                <PrePosition X="0" Y="0" />
                <PreSize X="0" Y="0" />
                <Children>
                  <NodeObjectData Name="Sprite_Bossblood" ActionTag="873726055" FrameEvent="" Tag="67" ObjectIndex="4" ctype="SpriteObjectData">
                    <Position X="-29.80341" Y="25.26041" />
                    <Scale ScaleX="0.9999998" ScaleY="0.9999924" />
                    <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <Size X="55" Y="63" />
                    <PrePosition X="-0.1072065" Y="0.4766114" />
                    <PreSize X="0" Y="0" />
                    <FileData Type="Normal" Path="Common/Cn17.png" />
                  </NodeObjectData>
                  <NodeObjectData Name="LoadingBar_Bossblood" ActionTag="82174315" FrameEvent="" Tag="161" ObjectIndex="20" ProgressInfo="80" ctype="LoadingBarObjectData">
                    <Position X="115.691" Y="26.91414" />
                    <Scale ScaleX="1" ScaleY="2.5" />
                    <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                    <CColor A="255" R="253" G="5" B="5" />
                    <Size X="200" Y="14" />
                    <PrePosition X="0.4161548" Y="0.5078139" />
                    <PreSize X="0" Y="0" />
                    <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" />
                  </NodeObjectData>
                </Children>
                <FileData Type="Normal" Path="BattleScene/BS14.png" />
              </NodeObjectData>
            </Children>
            <FileData Type="Normal" Path="generalshark.csd" />
          </NodeObjectData>
          <NodeObjectData Name="ProjectNode_Monster" ActionTag="559631451" FrameEvent="" Tag="5989" ObjectIndex="114" IconVisible="True" ctype="ProjectNodeObjectData">
            <Position X="458.3348" Y="332.7437" />
            <Scale ScaleX="1" ScaleY="1" />
            <AnchorPoint />
            <CColor A="255" R="255" G="255" B="255" />
            <Size X="0" Y="0" />
            <PrePosition X="0" Y="0" />
            <PreSize X="0" Y="0" />
            <Children>
              <NodeObjectData Name="Sprite_Monsterbloodbg" ActionTag="609553287" FrameEvent="" Tag="6122" ObjectIndex="377" ctype="SpriteObjectData">
                <Position X="46.45642" Y="168.443" />
                <Scale ScaleX="0.7921084" ScaleY="0.7991461" />
                <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="278" Y="53" />
                <PrePosition X="0" Y="0" />
                <PreSize X="0" Y="0" />
                <Children>
                  <NodeObjectData Name="Sprite_Monsterblood" ActionTag="116364811" FrameEvent="" Tag="6123" ObjectIndex="378" ctype="SpriteObjectData">
                    <Position X="-29.80341" Y="25.26041" />
                    <Scale ScaleX="0.9999998" ScaleY="0.9999924" />
                    <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <Size X="55" Y="63" />
                    <PrePosition X="0" Y="0" />
                    <PreSize X="0" Y="0" />
                    <FileData Type="Normal" Path="Common/Cn17.png" />
                  </NodeObjectData>
                  <NodeObjectData Name="LoadingBar_Monsterblood" ActionTag="758327566" FrameEvent="" Tag="6124" ObjectIndex="21" ProgressInfo="80" ctype="LoadingBarObjectData">
                    <Position X="115.691" Y="26.91414" />
                    <Scale ScaleX="1" ScaleY="2.5" />
                    <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                    <CColor A="255" R="253" G="5" B="5" />
                    <Size X="200" Y="14" />
                    <PrePosition X="0" Y="0" />
                    <PreSize X="0" Y="0" />
                    <ImageFileData Type="Default" Path="Default/LoadingBarFile.png" />
                  </NodeObjectData>
                </Children>
                <FileData Type="Normal" Path="BattleScene/BS14.png" />
              </NodeObjectData>
            </Children>
            <FileData Type="Normal" Path="tentacle.csd" />
          </NodeObjectData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>