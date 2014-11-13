<GameProjectFile>
  <PropertyGroup Type="Node" Name="BattleTop" ID="7def0ece-ff34-4ec8-b294-67f0a51a07d5" Version="2.0.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="0" Speed="1" />
      <ObjectData Name="Node_1" CanEdit="False" FrameEvent="" ctype="SingleNodeObjectData">
        <Position X="0" Y="0" />
        <Scale ScaleX="1" ScaleY="1" />
        <AnchorPoint />
        <CColor A="255" R="255" G="255" B="255" />
        <Size X="0" Y="0" />
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
              <NodeObjectData Name="Panel_Infobox" ActionTag="54" ZOrder="1" FrameEvent="" Tag="26" TouchEnable="True" BackColorAlpha="100" ComboBoxIndex="1" ColorAngle="0" Scale9Width="640" Scale9Height="140" ctype="PanelObjectData">
                <Position X="0" Y="818.2153" />
                <Scale ScaleX="1" ScaleY="1" />
                <AnchorPoint />
                <CColor A="255" R="255" G="255" B="255" />
                <Size X="640" Y="140" />
                <PrePosition X="0" Y="0.8523076" />
                <PreSize X="0" Y="0" />
                <Children>
                  <NodeObjectData Name="Button_Pause" ActionTag="59" IsAutoSize="True" FrameEvent="" Tag="41" TouchEnable="True" FontSize="14" ButtonText="" Scale9Width="46" Scale9Height="36" DisplayState="False" ctype="ButtonObjectData">
                    <Position X="604.9261" Y="90.21655" />
                    <Scale ScaleX="1" ScaleY="1" />
                    <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <Size X="46" Y="36" />
                    <PrePosition X="0" Y="0" />
                    <PreSize X="0" Y="0" />
                    <TextColor A="255" R="255" G="255" B="255" />
                    <DisabledFileData Type="Normal" Path="BattleScene/BS06.png" />
                    <PressedFileData Type="Normal" Path="BattleScene/BS05.png" />
                    <NormalFileData Type="Default" Path="Default/Button_Normal.png" />
                  </NodeObjectData>
                  <NodeObjectData Name="Button_Blast" ActionTag="230915546" FrameEvent="" Tag="41" ObjectIndex="1" TouchEnable="True" FontSize="14" ButtonText="" Scale9Width="61" Scale9Height="59" ctype="ButtonObjectData">
                    <Position X="597.7885" Y="31.31592" />
                    <Scale ScaleX="1" ScaleY="1" />
                    <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <Size X="61" Y="59" />
                    <PrePosition X="0.9340445" Y="0.2236851" />
                    <PreSize X="0" Y="0" />
                    <TextColor A="255" R="255" G="255" B="255" />
                    <DisabledFileData Type="Default" Path="Default/Button_Disable.png" />
                    <PressedFileData Type="Normal" Path="BattleScene/BS04.png" />
                    <NormalFileData Type="Normal" Path="BattleScene/BS03.png" />
                  </NodeObjectData>
                  <NodeObjectData Name="ImageView_Coinbg" ActionTag="45" ZOrder="1" FrameEvent="" Tag="25" Scale9Width="188" Scale9Height="54" ctype="ImageViewObjectData">
                    <Position X="310.4388" Y="93.04388" />
                    <Scale ScaleX="1" ScaleY="1" />
                    <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <Size X="188" Y="54" />
                    <PrePosition X="0" Y="0" />
                    <PreSize X="0" Y="0" />
                    <Children>
                      <NodeObjectData Name="AtlastLabel_Coincount" ActionTag="42" ZOrder="3" IsAutoSize="True" FrameEvent="" Tag="22" CharWidth="14" CharHeight="18" LabelText="12345&#xA;" StartChar="/" ctype="TextAtlasObjectData">
                        <Position X="45.78534" Y="28.6095" />
                        <Scale ScaleX="1" ScaleY="1" />
                        <AnchorPoint ScaleY="0.5" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <Size X="85" Y="18" />
                        <PrePosition X="0" Y="0" />
                        <PreSize X="0" Y="0" />
                        <LabelAtlasFileImage_CNB Type="Default" Path="Default/TextAtlas.png" />
                      </NodeObjectData>
                      <NodeObjectData Name="ImageView_Coin" ActionTag="783931732" ZOrder="2" FrameEvent="" Tag="38" ObjectIndex="2" Scale9Width="57" Scale9Height="53" ctype="ImageViewObjectData">
                        <Position X="13.37115" Y="29.69714" />
                        <Scale ScaleX="1" ScaleY="1" />
                        <AnchorPoint ScaleX="0.4384333" ScaleY="0.4641103" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <Size X="57" Y="53" />
                        <PrePosition X="0.07112316" Y="0.5499471" />
                        <PreSize X="0" Y="0" />
                        <FileData Type="Normal" Path="Common/Cn16.png" />
                      </NodeObjectData>
                    </Children>
                    <FileData Type="Normal" Path="BattleScene/BS13.png" />
                  </NodeObjectData>
                  <NodeObjectData Name="ImageView_Starbg" ActionTag="1015983839" ZOrder="1" FrameEvent="" Tag="37" ObjectIndex="1" Scale9Width="188" Scale9Height="54" ctype="ImageViewObjectData">
                    <Position X="116.8748" Y="90.00391" />
                    <Scale ScaleX="1" ScaleY="1" />
                    <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <Size X="188" Y="54" />
                    <PrePosition X="0.1826169" Y="0.642885" />
                    <PreSize X="0" Y="0" />
                    <Children>
                      <NodeObjectData Name="Text_Starname" ActionTag="187292493" FrameEvent="" Tag="40" ObjectIndex="1" FontSize="20" LabelText="Cocos " ctype="TextObjectData">
                        <Position X="103.5279" Y="28.56323" />
                        <Scale ScaleX="1" ScaleY="1" />
                        <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <Size X="64" Y="27" />
                        <PrePosition X="0.5506803" Y="0.5289487" />
                        <PreSize X="0" Y="0" />
                      </NodeObjectData>
                      <NodeObjectData Name="ImageView_Star" ActionTag="640445187" ZOrder="2" FrameEvent="" Tag="39" ObjectIndex="3" Scale9Width="68" Scale9Height="57" ctype="ImageViewObjectData">
                        <Position X="20.15009" Y="29.43549" />
                        <Scale ScaleX="1.127097" ScaleY="1.221221" />
                        <AnchorPoint ScaleX="0.4384333" ScaleY="0.4641103" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <Size X="68" Y="57" />
                        <PrePosition X="0.1071813" Y="0.5451016" />
                        <PreSize X="0" Y="0" />
                        <Children>
                          <NodeObjectData Name="Text_Star" ActionTag="304086378" FrameEvent="" Tag="166" ObjectIndex="3" FontSize="20" LabelText="234&#xA; " ctype="TextObjectData">
                            <Position X="33.90344" Y="16.73376" />
                            <Scale ScaleX="1" ScaleY="1" />
                            <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                            <CColor A="255" R="255" G="255" B="255" />
                            <Size X="36" Y="54" />
                            <PrePosition X="0.49858" Y="0.2935748" />
                            <PreSize X="0" Y="0" />
                          </NodeObjectData>
                        </Children>
                        <FileData Type="Normal" Path="Common/Cn20.png" />
                      </NodeObjectData>
                    </Children>
                    <FileData Type="Normal" Path="BattleScene/BS13.png" />
                  </NodeObjectData>
                  <NodeObjectData Name="ImageView_Micoinbg" ActionTag="48" ZOrder="1" FrameEvent="" Tag="28" Scale9Enable="True" Scale9Width="188" Scale9Height="54" ctype="ImageViewObjectData">
                    <Position X="489.9266" Y="91.52399" />
                    <Scale ScaleX="1" ScaleY="1" />
                    <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <Size X="188" Y="54" />
                    <PrePosition X="0.7655103" Y="0.6537428" />
                    <PreSize X="0" Y="0" />
                    <Children>
                      <NodeObjectData Name="ImageView_Micoincount" ActionTag="49" ZOrder="3" IsAutoSize="True" FrameEvent="" Tag="29" CharWidth="14" CharHeight="18" LabelText="2345" StartChar="/" ctype="TextAtlasObjectData">
                        <Position X="63.47308" Y="26.87494" />
                        <Scale ScaleX="1" ScaleY="1" />
                        <AnchorPoint ScaleY="0.5" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <Size X="56" Y="18" />
                        <PrePosition X="0" Y="0" />
                        <PreSize X="0" Y="0" />
                        <LabelAtlasFileImage_CNB Type="Default" Path="Default/TextAtlas.png" />
                      </NodeObjectData>
                      <NodeObjectData Name="ImageView_Coin" ActionTag="44" ZOrder="2" FrameEvent="" Tag="24" Scale9Width="62" Scale9Height="62" ctype="ImageViewObjectData">
                        <Position X="21.01343" Y="27.91229" />
                        <Scale ScaleX="1" ScaleY="1" />
                        <AnchorPoint ScaleX="0.4384333" ScaleY="0.4641103" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <Size X="62" Y="62" />
                        <PrePosition X="0.1117736" Y="0.5168943" />
                        <PreSize X="0" Y="0" />
                        <FileData Type="Normal" Path="Common/Cn19.png" />
                      </NodeObjectData>
                    </Children>
                    <FileData Type="Normal" Path="BattleScene/BS13.png" />
                  </NodeObjectData>
                  <NodeObjectData Name="ImageView_Yellowbg" ActionTag="229602682" FrameEvent="" Tag="42" ObjectIndex="4" Scale9Width="180" Scale9Height="62" ctype="ImageViewObjectData">
                    <Position X="77.78918" Y="37.96606" />
                    <Scale ScaleX="0.5" ScaleY="0.7" />
                    <AnchorPoint ScaleX="0.4462693" ScaleY="0.5271025" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <Size X="180" Y="62" />
                    <PrePosition X="0.1215456" Y="0.2711862" />
                    <PreSize X="0" Y="0" />
                    <Children>
                      <NodeObjectData Name="ImageView_Yellow" ActionTag="133432043" FrameEvent="" Tag="47" ObjectIndex="8" Scale9Width="52" Scale9Height="43" ctype="ImageViewObjectData">
                        <Position X="-51.63538" Y="17.48694" />
                        <Scale ScaleX="1.6" ScaleY="1.6" />
                        <AnchorPoint ScaleY="0.2683278" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <Size X="52" Y="43" />
                        <PrePosition X="-0.2868632" Y="0.2820474" />
                        <PreSize X="0" Y="0" />
                        <FileData Type="Normal" Path="BattleScene/BS01.png" />
                      </NodeObjectData>
                      <NodeObjectData Name="TextAtlas_Yellowcount" ActionTag="2120877381" FrameEvent="" Tag="9349" ObjectIndex="4" CharWidth="14" CharHeight="18" LabelText="0/5" StartChar="." ctype="TextAtlasObjectData">
                        <Position X="87.55005" Y="34.06604" />
                        <Scale ScaleX="1.8" ScaleY="1.8" />
                        <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <Size X="42" Y="18" />
                        <PrePosition X="0.4863892" Y="0.5494522" />
                        <PreSize X="0" Y="0" />
                        <LabelAtlasFileImage_CNB Type="Default" Path="Default/TextAtlas.png" />
                      </NodeObjectData>
                    </Children>
                    <FileData Type="Normal" Path="BattleScene/BS08.png" />
                  </NodeObjectData>
                  <NodeObjectData Name="ImageView_Redbg" ActionTag="474122064" FrameEvent="" Tag="43" ObjectIndex="5" Scale9Width="180" Scale9Height="62" ctype="ImageViewObjectData">
                    <Position X="208.7654" Y="38.42139" />
                    <Scale ScaleX="0.5" ScaleY="0.7" />
                    <AnchorPoint ScaleX="0.5775876" ScaleY="0.5387414" />
                    <CColor A="255" R="255" G="255" B="255" />
                    <Size X="180" Y="62" />
                    <PrePosition X="0.3261959" Y="0.2744385" />
                    <PreSize X="0" Y="0" />
                    <Children>
                      <NodeObjectData Name="ImageView_Red" ActionTag="210429249" FrameEvent="" Tag="48" ObjectIndex="9" Scale9Width="47" Scale9Height="39" ctype="ImageViewObjectData">
                        <Position X="-19.13086" Y="25.67358" />
                        <Scale ScaleX="1.6" ScaleY="1.6" />
                        <AnchorPoint ScaleX="0.3655629" ScaleY="0.3335336" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <Size X="47" Y="39" />
                        <PrePosition X="-0.1062826" Y="0.41409" />
                        <PreSize X="0" Y="0" />
                        <FileData Type="Normal" Path="BattleScene/BS02.png" />
                      </NodeObjectData>
                      <NodeObjectData Name="TextAtlas_Redcount" ActionTag="2120877382" FrameEvent="" Tag="9350" ObjectIndex="5" CharWidth="14" CharHeight="18" LabelText="0/4" StartChar="." ctype="TextAtlasObjectData">
                        <Position X="82.18" Y="34.05" />
                        <Scale ScaleX="1.8" ScaleY="1.8" />
                        <AnchorPoint ScaleX="0.5" ScaleY="0.5" />
                        <CColor A="255" R="255" G="255" B="255" />
                        <Size X="42" Y="18" />
                        <PrePosition X="0.4565555" Y="0.5491936" />
                        <PreSize X="0" Y="0" />
                        <LabelAtlasFileImage_CNB Type="Default" Path="Default/TextAtlas.png" />
                      </NodeObjectData>
                    </Children>
                    <FileData Type="Normal" Path="BattleScene/BS08.png" />
                  </NodeObjectData>
                </Children>
                <FileData Type="Normal" Path="BattleScene/BS11.png" />
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
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameProjectFile>