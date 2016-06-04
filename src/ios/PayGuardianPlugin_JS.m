#import "PayGuardianPlugin_JS.h"

@implementation PayGuardianPlugin_JS

NSString *const kCDVPluginINIT		= @"(function() {console.log('kCDVPluginINIT evaluated!');})();";
NSString *const kCDVPluginFUNCTION = @"(function() {console.log('kCDVPluginFUNCTION evaluated!');})();";
NSString *const kCDVPluginALERT = @"window.alert('MESSAGE CDVPlugin_JS.m LINE:37',alertDismissed,'Event Create & Saved','OK');";

@end
