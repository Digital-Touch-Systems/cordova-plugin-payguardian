@import Foundation;

@class ChipCardRead;
@class BPNPayment;
@class BPNPaymentRequest;

typedef NS_ENUM(NSUInteger, PayGuardianTransactionState) {
    PayGuardianTransactionStateNotStarted,
    PayGuardianTransactionStateWaitingForCard,
    PayGuardianTransactionStateReadingCard,
    PayGuardianTransactionStateChipCardWithUnreadChipSwiped,
    PayGuardianTransactionStateCardReadWithBrokenChip,
    PayGuardianTransactionStateCardReadWithError,
    PayGuardianTransactionStateWaitingForGateway,
    PayGuardianTransactionStateRespondingToCard,
    PayGuardianTransactionStateVoiding,
    PayGuardianTransactionStateFinished
};


@interface PayGuardianTransaction : NSObject

@property (nonatomic, assign, readonly) PayGuardianTransactionState state;

- (instancetype)init __unavailable;
// clang-format off
+ (instancetype)new __unavailable;
// clang-format on
- (instancetype)initWithPaymentRequest:(BPNPaymentRequest *)request;

- (void)runOnCompletion:(void (^)(BPNPayment *payment, NSError *error)) onCompletion
         onStateChanged:(void (^)(PayGuardianTransactionState state)) onStateChanged;

- (void) testMagtek;

- (void)cancel;

- (void) UNIPAY_startEmv;

@property (nonatomic, assign) BOOL retryOnBadRead;

@end
