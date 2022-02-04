#
# Be sure to run `pod lib lint ${POD_NAME}.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'Twisto'
  s.version          = '1.6.0'
  s.summary          = 'Twisto iOS SDK framework'

  s.description      = <<-DESC
Twisto iOS SDK framework to integrate Twisto payment method to iOS application.
                       DESC

  s.homepage         = 'https://www.twisto.cz'
  s.license      = { :type => 'Copyright',
                     :text => <<-LICENSE
Copyright 2016 Twisto Payments a.s. All rights reserved.
                            LICENSE
  }
  s.author           = { 'Twisto Payments a.s.' => 'devs@twisto.cz' }
  s.source           = { :git => 'https://github.com/TwistoPayments/ios-sdk-bin.git', :tag => '1.6.0' }
  s.platform = :ios
  s.ios.deployment_target = '12.0'

  s.ios.vendored_frameworks = 'iOS/Twisto.xcframework'

  s.preserve_path      = 'iOS/*'
  s.requires_arc = true
end
