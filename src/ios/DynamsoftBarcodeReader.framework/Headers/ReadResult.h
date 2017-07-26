
#import <Foundation/Foundation.h>

/*!
 @class ReadResult
 @abstract A class that stores all barcodes that has been read, error code and error string occurred during reading.
 */
@interface ReadResult : NSObject

/** Indicate what an error occurred. If no error is occurred, it's [BarcodeReader DBRERROR_OK]. */
@property(nonatomic) int errorCode;

/** The detailed information about the error is occurred. If no error occurred, it's "Successful". */
@property(nonatomic, copy) NSString *errorString;

/** Represent all found barcodes. If no barcode is found, it's nil. */
@property(nonatomic) NSArray *barcodes;

@end
