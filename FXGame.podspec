Pod::Spec.new do |s|
  s.name         = "FXGame"
  s.version      = "1.0.0"
  s.summary      = "基于cocos2d的游戏组件"

  s.homepage     = "https://github.com/zqw87699/FXGame"

  s.license      = { :type => "MIT", :file => "LICENSE" }

  s.author       = {"zhangdazong" => "929013100@qq.com"}

  s.source       = { :git => "https://github.com/zqw87699/FXGame.git", :tag => "#{s.version}"}

  s.platform     = :ios, "7.0"

  s.source_files  = "FXGame/Classes/*.{h,m}"

  s.public_header_files = "FXGame/Classes/*.h"

  s.module_name = 'FXGame'

  s.requires_arc = true

end
