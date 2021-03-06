#import <Cordova/CDVAvailability.h>
#import <Cordova/CDVViewController.h>

#import <PayGuardian_SDK/PayGuardian_SDK.h>

#import "PayGuardianPlugin.h"

@implementation PayGuardianPlugin

- (void)initWithAmount:(CDVInvokedUrlCommand *)command {
    NSLog(@"Checking status");
    [self.commandDelegate runInBackground:^{
				//NSDecimalNumber *amount = [NSDecimalNumber decimalNumberWithString:[command.arguments objectAtIndex:0]; //???
        CDVPluginResult	*result = nil;

        for (id object in command.arguments)
        {
          NSLog(@"%@", object);
        }

        @try {
					// RBAConnectionQueue *q = [[RBAConnectionQueue alloc] init];
					// BPNPaymentRequest *r = [[BPNPaymentRequest alloc] initWithAmount:amount tipAmount:nil invoiceNumber:@"1234" tenderType:TENDER_TYPE_CREDIT transactionType:TRANSACTION_TYPE_SALE username:@"merchUser" password:@"merchPass" merchantCode:@"merchCode" merchantAccountCode:@"mac" originalReferenceNumber:nil connectionService:nil connectionQueue:q cashBackAmount:nil PaymentAccountNumber:nil ExpirationDate:nil shippingAddress:nil DeviceType:nil testMode:YES];
          //
    			// PayGuardianTransaction *t = [[PayGuardianTransaction alloc] initWithPaymentRequest:r];
					//???
          //NSDictionary *statusDictionary = [self portStatusToDictionary:status];
          //result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsDictionary:statusDictionary];
        }
        @catch (NSException *exception) {
            NSLog(@"Exception");
        }

				//???
        [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
    }];
}

@end
