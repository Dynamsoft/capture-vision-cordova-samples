
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*!
 @class Barcode
 @abstract A class that stores all the information of a barcode, including it's format, content, location, etc.
 */
@interface Barcode : NSObject

/** Represent barcode type. */
@property(nonatomic) long format;

/** Barcode format in "NSString" format. */
@property(nonatomic, copy) NSString *formatString;

/** Barcode's data in "NSString" format. */
@property(nonatomic, copy) NSString *displayValue;

/** Barcode's data in "NSData" format. */
@property(nonatomic, copy) NSData *rawValue;

/** The locations of the barcode's four vertices. */
@property(nonatomic, copy) NSArray *cornerPoints;

/** The minimum rectangle area that contains the barcode. */
@property(nonatomic) CGRect boundingbox;

//All 1D
/*!
 @method OneD
 @abstract Static method. Get 1D barcode format.
 @result A long type number.
 */
+(long) OneD;

//1D
/*!
 @method CODE_39
 @abstract Static method. Get CODE 39 barcode format.
 @result A long type number.
 */
+(long) CODE_39;

/*!
 @method CODE_128
 @abstract Static method. Get CODE 128 barcode format.
 @result A long type number.
 */
+(long) CODE_128;

/*!
 @method CODE_93
 @abstract Static method. Get CODE 93 barcode format.
 @result A long type number.
 */
+(long) CODE_93;

/*!
 @method CODABAR
 @abstract Static method. Get Codabar barcode format.
 @result A long type number.
 */
+(long) CODABAR;

/*!
 @method ITF
 @abstract Static method. Get ITF barcode format.
 @result A long type number.
 */
+(long) ITF;

/*!
 @method EAN_13
 @abstract Static method. Get EAN-13 barcode format.
 @result A long type number.
 */
+(long) EAN_13;

/*!
 @method EAN_8
 @abstract Static method. Get EAN-8 barcode format.
 @result A long type number.
 */
+(long) EAN_8;

/*!
 @method UPC_A
 @abstract Static method. Get UPC-A barcode format.
 @result A long type number.
 */
+(long) UPC_A;

/*!
 @method UPC_E
 @abstract Static method. Get UPC-E barcode format.
 @result A long type number.
 */
+(long) UPC_E;

/*!
 @method INDUSTRIAL_25
 @abstract Static method. Get Industrial 2 of 5 barcode format.
 @result A long type number.
 */
+(long) INDUSTRIAL_25;

//2D
/*!
 @method PDF417
 @abstract Static method. Get PDF417 barcode format.
 @result A long type number.
 */
+(long) PDF417;

/*!
 @method DATAMATRIX
 @abstract Static method. Get DataMatrix barcode format.
 @result A long type number.
 */
+(long) DATAMATRIX;

/*!
 @method QR_CODE
 @abstract Static method. Get QRCode barcode format.
 @result A long type number.
 */
+(long) QR_CODE;

//UNKNOWN
/*!
 @method UNKNOWN
 @abstract Static method. Get all barcode formats.
 @result A long type number.
 */
+(long) UNKNOWN;

@end
