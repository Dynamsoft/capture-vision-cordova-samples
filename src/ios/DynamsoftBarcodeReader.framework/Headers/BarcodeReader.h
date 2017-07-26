
#import "Barcode.h"
#import "ReadResult.h"

/*!
 @class BarcodeReader
 @abstract The BarcodeReader class is used to read a barcode from UIImage object or NV21 data(Camera). It offers both synchronous and asynchronous methods for that.
 */
@interface BarcodeReader : NSObject

/**
 * Error Code - static methods
 */

+(int) DBRERROR_OK;
+(int) DBRERROR_UNKNOWN;
+(int) DBRERROR_NOMEMORY;
+(int) DBRERROR_NULL_POINTER;
+(int) DBRERROR_LICENSE_INVALID;
+(int) DBRERROR_LICENSE_EXPIRED;
+(int) DBRERROR_BARCODE_FORMAT_INVALID;
+(int) DBRERROR_PARAMETER_INVALID;

/*!
 @method initWithLicense :
 @abstract Init BarcodeReader with license.
 @param license Dynamsoft Barcode Reader license.
 @result An initialized BarcodeReader object, or nil if an object could not be created for some reason that would not result in an exception.
 */
-(id) initWithLicense : (NSString *) license;

/*!
 @method readSingleAsync : barcodeFormat :
 @abstract Tries to read a barcode from an image in sync manner.
 @param image The image for detection.
 @param format Specified barcode format.
 @result Reading result that contains barcode has ben read, error code and error string if error occurred during reading.
 */
-(ReadResult *) readSingle : (UIImage *) image
             barcodeFormat : (long) format;

/*!
 @method readSingleAsync : barcodeFormat : sender : onComplete:
 @abstract Tries to read a barcode from an image in async manner.
 @param image The image for detection.
 @param format Specified barcode format.
 @param sender ID of the object with the callback method to be invoked.
 @param callback Selector of the callback method.
 @result Void.
 */
-(void)readSingleAsync : (UIImage *) image
         barcodeFormat : (long) format
                sender : (id)sender
            onComplete : (SEL)callback;

/*!
 @method readSingle : width : height : barcodeFormat: 
 @abstract Tries to read a barcode from an NV21 image buffer in sync manner.
 @param buffer The NV21 byte array(NSData *).
 @param width Image's width.
 @param height Image's height.
 @param format Specified barcode format.
 @result Reading result that contains barcode has ben read, error code and error string if error occurred during reading.
 */
-(ReadResult *)readSingle : (NSData *) buffer
                    width : (int) width
                   height : (int) height
            barcodeFormat : (long) format;

/*!
 @method readSingleAsync : width : height : barcodeFormat : sender : onComplete : 
 @abstract Tries to read a barcode from an NV21 image buffer in async manner.
 @param buffer The NV21 byte array(NSData *).
 @param width Image's width.
 @param height Image's height.
 @param format Specified barcode format.
 @param sender ID of the object with the callback method to be invoked.
 @param callback Selector of the callback method.
 @result Void.
 */
-(void)readSingleAsync : (NSData *) buffer
                 width : (int) width
                height : (int) height
         barcodeFormat : (long) format
                sender : (id)sender
            onComplete : (SEL)callback;

@end
