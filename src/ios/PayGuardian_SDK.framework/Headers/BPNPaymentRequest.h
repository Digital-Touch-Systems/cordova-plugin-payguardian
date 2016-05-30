@import Foundation;

NS_ASSUME_NONNULL_BEGIN

@class BPNAddress;
@class RBAConnectionQueue;
@protocol RBAConnectionService;


@interface BPNPaymentRequest : NSObject

// Total transaction amount (includes subtotal, cash back, tax, and tip)
@property (strong, nonatomic, readonly) NSDecimalNumber *amount;


// Total transaction DeviceType ]
@property (strong, nonatomic, readonly) NSString *DeviceType;

// test mode on or off
@property (nonatomic, assign, readonly) BOOL testMode;

// Tip amount only
@property (strong, nonatomic, readonly) NSDecimalNumber *tipAmount;

// Unique ID for the transaction
@property (strong, nonatomic, readonly) NSString *transactionID;

// Valid values available under TENDER_TYPE
@property (strong, nonatomic, readonly) NSString *tenderType;

// Unique ID for the transaction
@property (strong, nonatomic, readonly) NSString *ExpirationDate;

// Valid values available under PaymentAccountNumber
@property (strong, nonatomic, readonly) NSString *PaymentAccountNumber;

// Valid values are available under TRANSACTION_TYPE
@property (strong, nonatomic, readonly) NSString *transactionType;

// Gateway username for the merchant
@property (strong, nonatomic, readonly) NSString *username;

// Gateway password for the merchant
@property (strong, nonatomic, readonly) NSString *password;

@property (strong, nonatomic, readonly) NSString *merchantCode;

@property (strong, nonatomic, readonly) NSString *merchantAccountCode;

// Only required for voids and refunds
@property (strong, nonatomic, nullable, readonly) NSString *originalReferenceNumber;

// Service responsible for connecting to an RBA device. If none is provided, a default implementation will be used.
@property (nonatomic, strong, readonly) id<RBAConnectionService> connectionService;

// A queue used to control access to the RBA device. A single instance of this queue
// should be used throughout your application.
@property (nonatomic, strong, readonly) RBAConnectionQueue *connectionQueue;

// Not implemented
@property (strong, nonatomic, nullable, readonly) NSDecimalNumber *cashBackAmount;

@property (strong, nonatomic, nullable, readonly) BPNAddress *shippingAddress;

- (instancetype)init __unavailable;
// clang-format off
+ (instancetype)new __unavailable;
// clang-format on
NS_ASSUME_NONNULL_END

- (BPNPaymentRequest *_Nonnull)initWithAmount:(NSDecimalNumber *_Nonnull)amount
                     tipAmount:(NSDecimalNumber *_Nullable)tipAmount
                 invoiceNumber:(NSString *_Nonnull)invoiceNumber
                    tenderType:(NSString *_Nonnull)tenderType
               transactionType:(NSString *_Nonnull)transactionType
                      username:(NSString *_Nonnull)username
                      password:(NSString *_Nonnull)password
                  merchantCode:(NSString *_Nonnull)merchantCode
           merchantAccountCode:(NSString *_Nonnull)merchantAccountCode
       originalReferenceNumber:(NSString *_Nullable)originalReferenceNumber
             connectionService:(NSObject<RBAConnectionService> *_Nullable)connectionService
               connectionQueue:(RBAConnectionQueue *_Nonnull)connectionQueue
                cashBackAmount:(NSDecimalNumber *_Nullable)cashBackAmount
          PaymentAccountNumber:(NSString *_Nullable) PaymentAccountNumber
                ExpirationDate:(NSString *_Nullable) ExpirationDate
               shippingAddress:(BPNAddress *_Nullable)shippingAddress
                    DeviceType:(NSString *_Nullable)DeviceType
                                     testMode:(BOOL) testMode;

@end


