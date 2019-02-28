/**
 *
 * @mainpage 
 * 
 * @section Introduction
 * Dynamsoft's Barcode Reader SDK enables you to efficiently embed barcode reading functionality in your application using just a few lines of code. This can save you from months of added development time and extra costs. 
 * With the Barcode Reader SDK, you can decode barcodes from various image file formats (bmp, jpg, png, gif, tiff and pdf) as well as device-independent bitmap (DIB) which has just been obtained from cameras and scanners, etc.
 * The SDK has the multiple editions available include Windows, JavaScript, Moblie, Linux, Raspberry Pi and Mac. This document contains detailed API references for iOS.
 *
 * @section mp1 Barcode Reading Features
 * - Reads barcodes within a specified area of a selected image.
 * - Reads multiple barcodes in one image.
 * - Can read blurred and damaged barcodes.
 * - Detects barcode at any orientation and rotation angle.
 *
 * @section mp2 Supported Barcode Type
 * - 1D barcodes: Code39, Code93, Code128, Codabar, ITF, EAN13, EAN8, UPCA, UPCE, INDUSTRIAL 2 OF 5.
 * - 2D barcodes: QRCode, PDF417, DATAMATRIX, AZTEC.
 *
 * @section mp3 Barcode Reading Results
 * - Barcode angle
 * - Barcode type
 * - Barcode count
 * - Barcode data as byte array
 * - Barcode value as string
 * - Barcode bounding rectangle
 * - Confidence
 * - Coordinate of four corners
 * - Module size
 * - Page number
 * - Terminated stage
 * 
 * @section mp4 Supported Image Source Types
 * - Bmp, jpg, png, tiff and pdf image files; multi-page tiff and pdf are also supported
 * - Windows DIB and .NET bitmap
 * - Black/white, grayscale or color
 * 
 * @section mp5 Contents - iOS
 * @subsection sbs1 Enumerations
 *		- [Barcode Type](@ref BarcodeType)
 *		- [DBR Conflict Mode](@ref DBRConflictMode)
 *		- [DBR Error Code](@ref DBRErrorCode)
 *		- [Image Pixel Type](@ref ImagePixelType)
 *		- [Result Text Type](@ref ResultTextType)
 *		- [Terminate Status](@ref TerminateStatus)
 *
 * @subsection sbs2 Class
 *		- [Public Settings](@ref PublicSettings)
 *		- [Extended Result](@ref ExtendedResult)
 *		- [Localization Result](@ref LocalizationResult)
 *		- [Text Result](@ref TextResult)
 *		- [Dynamsoft Barcode Reader](@ref DynamsoftBarcodeReader)
 *
 */

#import <UIKit/UIKit.h>


static NSString* _Nonnull const DBRErrorDomain = @"com.dynamsoft.barcodereader.error";
/**
 * @defgroup IOSAPI iOS APIs
 * @{
 */


/**
 * @defgroup Enum Enumerations
 * @{
 */

/**
 * Describes the error codes. 
 * @enum DBRErrorCode
 */
typedef NS_ENUM(NSInteger, DBRErrorCode) {
    
    DBRErrorCode_Unknown                    = -10000,
	/**< Unknown error. */

    DBRErrorCode_No_Memory                  = -10001,    
	/**< Not enough memory to perform the operation. */

    DBRErrorCode_Null_Pointer               = -10002,
	/**< Null pointer. */

    DBRErrorCode_License_Invalid            = -10003,
	/**< The license is invalid. */

    DBRErrorCode_License_Expired            = -10004,   
	/**< The license has expired. */

    DBRErrorCode_File_Not_Found             = -10005,
	/**< The file is not found. */

    DBRErrorCode_Filetype_Not_Supported     = -10006,
	/**< The file type is not supported. */

    DBRErrorCode_BPP_Not_Supported          = -10007,
	/**< The BPP(Bits per pixel) is not supported. */

    DBRErrorCode_Index_Invalid              = -10008,
	/**< The index is invalid. */

    DBRErrorCode_Barcode_Format_Invalid     = -10009,
	/**< The barcode format is invalid. */

    DBRErrorCode_Custom_Region_Invalid      = -10010,
	/**< The input region value parameter is invalid. */

    DBRErrorCode_Max_Barcode_Number_Invalid = -10011,
	/**< The maximum barcode number is invalid. */

    DBRErrorCode_Image_Read_Failed          = -10012,
	/**< Failed to read the image. */

    DBRErrorCode_TIFF_Read_Failed           = -10013,  
	/**< Failed to read the TIFF image. */

    DBRErrorCode_QR_License_Invalid         = -10016,
	/**< The QR Code license is invalid. */

    DBRErrorCode_1D_Lincese_Invalid         = -10017,
	/**< The 1D Barcode license is invalid. */

    DBRErrorCode_PDF417_License_Invalid     = -10019,
	/**< The PDF417 license is invalid. */

    DBRErrorCode_Datamatrix_License_Invalid = -10020,
	/**< The DATAMATRIX license is invalid. */

    DBRErrorCode_PDF_Read_Failed            = -10021,
	/**< Failed to read the PDF file. */

    DBRErrorCode_PDF_DLL_Missing            = -10022,
	/**< The PDF DLL is missing. */

    DBRErrorCode_Page_Number_Invalid        = -10023,
	/**< The page number is invalid. */

    DBRErrorCode_Custom_Size_Invalid        = -10024,
	/**< The custom size is invalid. */

    DBRErrorCode_Custom_Modulesize_Invalid  = -10025,
	/**< The custom module size is invalid. */

    DBRErrorCode_Recognition_Timeout        = -10026,
	/**< Recognition timeout. */

    DBRErrorCode_Json_Parse_Failed          = -10030,
	/**< Failed to parse json string. */

    DBRErrorCode_Json_Type_Invalid          = -10031,
	/**< The value type is invalid. */

    DBRErrorCode_Json_Key_Invalid           = -10032,
	/**< The key is invalid. */

    DBRErrorCode_Json_Value_Invalid         = -10033,
	/**< The value is invalid or out of range. */

    DBRErrorCode_Json_Name_Key_Missing      = -10034,
	/**< The mandatory key "Name" is missing. */

    DBRErrorCode_Json_Name_Value_Duplicated = -10035,
	/**< The value of the key "Name" is duplicated. */

    DBRErrorCode_Template_Name_Invalid      = -10036,
	/**< The template name is invalid. */

    DBRErrorCode_Json_Name_Reference_Invalid = -10037,
	/**< The name reference is invalid. */

    DBRErrorCode_Parameter_Value_Invalid    = -10038,
	/**<The parameter value is invalid or out of range. */

    DBRErrorCode_Domain_Not_Matched         = -10039,
	/**<The domain of your current site does not match the domain bound in the current product key. */

    DBRErrorCode_ReservedInfo_Not_Matched   = -10040,
	/**<The reserved info does not match the reserved info bound in the current product key. */

    DBRErrorCode_AZTEC_License_Invalid      = -10041,
	/**< The AZTEC license is invalid. */
    
    DBRErrorCode_License_Dll_Missing        = -10042,
    /**< The License DLL is missing. */
    
    DBRErrorCode_Licensekey_Not_Matched     = -10043,
    /**< The license key is not match the license file. */
    
    DBRErrorCode_Licensefile_Expried        = -10044,
    /**< The license file is expried. */
    
    DBRErrorCode_Licensefile_Invalide       = -10045,
    /**< The license file is invalide. */
    
    DBRErrorCode_Requested_Failed           = -10046
    /**< Failed to request the license file. */
    
};

/**
 * Describes the type of the barcode. All the formats can be combined, such as BF_CODE_39 | BF_CODE_128.
 */
typedef NS_OPTIONS(NSInteger, BarcodeType) {
    BarcodeTypeCODE39     = 1 << 0,
	/**< Code 39 */

    BarcodeTypeCODE128    = 1 << 1,
	/**< Code 128 */

    BarcodeTypeCODE93     = 1 << 2,
	/**< Code 93 */

    BarcodeTypeCODABAR    = 1 << 3,
	/**< Codebar */

    BarcodeTypeITF        = 1 << 4,   
	/**< ITF */

    BarcodeTypeEAN13      = 1 << 5,
	/**< EAN-13 */

    BarcodeTypeEAN8       = 1 << 6,
	/**< EAN-8 */

    BarcodeTypeUPCA       = 1 << 7,
	/**< UPC-A */

    BarcodeTypeUPCE       = 1 << 8,
	/**< UPC-E */

    BarcodeTypeINDUSTRIAL = 1 << 9,
	/**< Industrial 2 of 5 */

    BarcodeTypePDF417     = 1 << 25,
	/**< PDF417 */

    BarcodeTypeQRCODE     = 1 << 26,
	/**< QRCode */

    BarcodeTypeDATAMATRIX = 1 << 27,
	/**< DataMatrix */

    BarcodeTypeAZTEC       = 1 << 28,
	/**< AZTEC */

    BarcodeTypeONED       = BarcodeTypeCODE39 | BarcodeTypeCODE128 |
                            BarcodeTypeCODE93 | BarcodeTypeCODABAR |
                            BarcodeTypeITF    | BarcodeTypeEAN13   |
                            BarcodeTypeEAN8   | BarcodeTypeUPCA    |
                            BarcodeTypeUPCE   | BarcodeTypeINDUSTRIAL,
	/**< One-D */

    BarcodeTypeALL        = BarcodeTypeONED   | BarcodeTypePDF417  |
                            BarcodeTypeQRCODE | BarcodeTypeDATAMATRIX|
                            BarcodeTypeAZTEC,
	/**< All supported formats */

};

/** Describes the image pixel format. */
typedef NS_ENUM(NSInteger, ImagePixelType) {
    ImagePixelTypeBinary,
	/**< 0:Black, 1:White */

    ImagePixelTypeBinaryInverted,
	/**< 0:White, 1:Black */

    ImagePixelTypeGrayScaled,
	/**< 8bit gray */

    ImagePixelTypeNV21,
	/**< NV21 */

    ImagePixelTypeRGB_565,
	/**< 16bit */

    ImagePixelTypeRGB_555,
	/**< 16bit */

    ImagePixelTypeRGB_888,
	/**< 24bit */

    ImagePixelTypeARGB_8888
	/**< 32bit */

};

/** Describes the extended result type. */
typedef NS_ENUM(NSInteger, ResultTextType) {
    ResultTextTypeStandardText,
	/**< Specifies the standard text. This means the barcode value. */

    ResultTextTypeRawText,
	/**< Specifies the raw text. This means the text that includes start/stop characters, check digits, etc. */

    ResultTextTypeCandidateText,
	/**< Specifies all the candidate text. This means all the standard text results decoded from the barcode. */

    ResultTextTypePartialText
	/**< Specifies the partial Text. This means part of the text result decoded from the barcode. */

};

/** Describes the status when the results are returned. */
typedef NS_ENUM(NSInteger, TerminateStatus) {
    TerminateStatusPrelocalized,
	/**< Prelocalized */

    TerminateStatusLocalized,
	/**< Localized */

    TerminateStatusRecognized
	/**< Recognized */
};

/** Describes the options for setting parameters value. Detailed info can be found in PublicSettings. */
typedef NS_ENUM(NSInteger, DBRConflictMode) {
	DBRECM_Ignore = 1,
	/**< Ignore new settings and inherit from previous settings. */

	DBRECM_Overwrite = 2,
	/**< overwrite and replace by new settings. */

};
/**
 * @}
 */


/**
 * @defgroup IOSInterface Class 
 * @{
 * @defgroup PublicSettings PublicSettings
 * @{
 */

 /** Values that represent text filter modes */
typedef NS_ENUM(NSInteger, TextFilter) {
    TextFilterDisable = 1,
	/**< Disable text filter */

    TextFilterEnable  = 2
	/**< Enable text filter */

};


/** Values that represent region predetection modes */
typedef NS_ENUM(NSInteger, RegionPredetection) {
    RegionPredetectionDisable = 1,
	/**< Disable region pre-detection */

    RegionPredetectionEnable  = 2
	/**< Enable region pre-detection */
};


/** Values that represent barcode invert modes */
typedef NS_ENUM(NSInteger, BarcodeInvert) {
    BarcodeInvertDarkOnLight,
	/**< Dark barcode region on light background. */

    BarcodeInvertLightOnDark
	/**< Light barcode region on dark background. */
};


/** Values that represent colour image convert modes */
typedef NS_ENUM(NSInteger, ColourImageConvert) {
    ColourImageConvertAuto,
	/**< Process input image as its original colour space. */

    ColourImageConvertGrayScale
	/**< Process input image with gray scale. */
};



/*--------------------------------------------------------------------*/

/**
 * @brief PublicSettings is used for storing current runtime settings.
 * 
 * The value of public parameters in runtime settings need to be set according to a specified rules if there are conflicts between different templates. The rules will been shown below:
 * 
 * @par Parameters Assignment Rules:
 * - Set as maximal value: timeout, PDFRasterDPI, deblurLevel, antiDamageLevel, maxDimOfFullImageAsBarcodeZone, maxBarcodeCount, scaleDownThreshold, expectedBarcodeCount.
 * 
 * - Set as union (merged or sum): barcodeTypeID.
 * 
 * - Based on ConflictMode (ignore or overwrite): textFilter, regionPredetection, localizationAlgorithmPriority, textureDetectionSensitivity, barcodeInvert, grayEqualizationSensitivity, enableFillBinaryVacancy, colourImageConvert, binarizationBlockSize.
 * 
 * 
 * @par References
 * More information about public parameters and template file can be found in file DBR_Developer's_Guide.pdf.
 * 
 */
@interface PublicSettings: NSObject


@property (nonatomic, nonnull) NSString * name;
/**< Stores the name of the struct, which is mainly help users to distinguish different version rather than practical use in the library.
 * @deprecated mName
 */


@property (nonatomic, assign) NSInteger timeout;
/**< Sets the maximum amount of time (in milliseconds) it should spend searching for a barcode per page. It does not include the time taken to load an image (Tiff, PNG, etc.) from disk into memory.
 *
 * @par Value range:
 * 	    [0,7ffffff]
 * @par Default value:
 * 	    10000
 * @par Remarks:
 *	    If you want to stop reading barcodes after a specified amount of time, you can use this parameter to set a timeout.
 */


@property (nonatomic, assign) NSInteger PDFRasterDPI;
/**< Sets the output image resolution. When you are trying to decode a PDF file using the DecodeFile method, the library will convert the PDF file to image(s) first, then perform barcode recognition.
 *
 * @par Value range:
 * 		[100,600]
 * @par Default value:
 * 		300
 * @par Remarks:
 *		To ensure your barcodes in the PDF files are readable, please set the resolution to at least 300 dpi.
 */


@property (nonatomic, assign) TextFilter textFilter;
/**< Sets whether to filter text before barcode localization.
 * 
 *  @par Value range:
 * 		TextFilterDisable, TextFilterEnable
 * 	@par Default value:
 *		TextFilterEnable
 * @par Remarks:
 *		If the barcode image contains a lot of text, you can set this property to "TextFilterEnable" to speed up the localization process.
 *	@sa TextFilter
 * 
 */


@property (nonatomic, assign) RegionPredetection regionPredetection;
/**< Sets whether to pre-detect barcode regions before accurate localization. 
 * 
 * @par Value range:
 * 		RegionPredetectionDisable, RegionPredetectionEnable
 * @par Default value:
 * 		RegionPredetectionDisable
 * @par Remarks:
 *		If the image is large and the barcode on the image is very small, it is recommended to set this property to "RPM_Enable" to speed up the localization process and recognition accuracy.
 *		If this property is set to "RegionPredetectionEnable", also set colourImageConvert to "ColourImageConvertAuto" and scaleDownThreshold to 0x7fffffff for best performance.
 * @sa RegionPredetection colourImageConvert scaleDownThreshold
 */


@property (nonatomic, nonnull) NSString * localizationAlgorithmPriority;
/**< Sets the priority of localization algorithms to decide the ordering of the following four localization algorithms.
 * 
 * @par Default values:
 * 		""
 * @par Optional localization algorithms:
 * 		"ConnectedBlocks", "Statistics", "Lines", "FullImageAsBarcodeZone"
 * @par Remarks:
 * 		- Default value: The library will automatically use optimized localization priority, i.e. ConnectedBlocks -> Statistics -> Lines -> FullImageAsBarcodeZone, which is also the recommended order.
 * 
 * 		- ConnectedBlocks: Localizes barcodes by searching connected blocks. This algorithm usually gives best result and it is recommended to set ConnectedBlock to the highest priority.
 * 
 * 		- Lines: Localizes barcodes by searching for groups of lines. This is optimized for 1D and PDF417 barcodes.
 * 
 * 		- Statistics: Localizes barcodes by groups of contiguous black-white regions. This is optimized for QRCode and DataMatrix.
 * 
 * 		- FullImageAsBarcodeZone: Disables localization. In this mode, it will directly localize barcodes on the full image without localization. If there is nothing other than the barcode in the image, it is recommended to use this mode.
 * 
 */


@property (nonatomic, assign) NSInteger barcodeTypeID;
/**< Sets which types of barcode to read. Barcode types can be combined. Notice that one barcode reader can support more than one barcode format, i.e. the barcode format can be combined like BarcodeTypeCODE39 | BarcodeTypeCODE128.
 * 
 * @par Remarks:
 *		If you already know the barcode type(s) before performing barcode reading, specifying the barcode type(s) to be read will speed up the recognition process.
 * @sa BarcodeType
 */


@property (nonatomic, assign) NSInteger textureDetectionSensitivity;
/**< ISets the value of sensitivity for texture detection. 
 *
 * @par Value range:
 * 		[0,9]
 * @par Default value:
 * 		5
 * @par Remarks:
 *		If you have an image with texture on it , you can set this property to a larger value. If texture is detected, we will smooth the image to help localize the barcode.
 *		If there is no texture on the image, the value should be set to 0 to disable texture detection; If there is texture on the image, you can set this value to 9 to activate texture detection.
 */


@property (nonatomic, assign) NSInteger deblurLevel;
/**< Sets the degree of blurriness of the barcode.
 * @par Value range:
 * 		[0,9]
 * @par Default value:
 * 		9
 * @par Remarks:
 *		If you have a blurry image, you can set this property to a larger value. The higher value you set, the library will spend more time decoding images which may slow down the overall recognition process.
 */

/**@brief The anti damage level */
@property (nonatomic, assign) NSInteger antiDamageLevel;
/**< Sets the degree of anti-damage of the barcode, which decides how many localization algorithms will be used for locating the barcode area.
 * @par Value range:
 * 		[0,9]
 * @par Default Value:
 * 		9
 * @par Remarks:
 * 		- 0 <= N <= 3: one localization algorithm will be used.
 * 
 * 		- 4 <= N <= 5: two localization algorithm will be used.
 * 
 * 		- 6 <= N <= 7: three localization algorithm will be used.
 * 
 * 		- 8 <= N <= 9: four(i.e. all) localization algorithm will be used.
 * 
 * 		If you have a damaged image, you can set this property to a larger value and use it with ExpectedBarcodesCount. 
 *		If the ExpectedBarcodesCount is set to 0 or 1, it's suggested to set AntiDamageLevel to 9 to ensure best decoding efficiency; otherwise, the value of AntiDamageLevel is suggested to be set to 7. For more information about our localization algorithms, please check AlgorithmPriority. 
 * 
 * @sa expectedBarcodeCount
 */


@property (nonatomic, assign) NSInteger maxDimOfFullImageAsBarcodeZone;
/**< Sets the maximum image dimension (in pixels) to localize barcode on the full image. If the image dimension is smaller than the given value, the library will localize barcode on the full image. Otherwise, "FullImageAsBarcodeZone" mode will not be enabled and we will only localize barcodes within the dimension provided.
 * 
 * @par Value range:
 * 		[262144,0x7fffffff]
 * @par Default value:
 * 		262144
 * @par Remarks:
 *		If you have an image whose content is barcode only, you can set this property to a smaller value to decode the whole image. 
 *		If the "FullImageAsBarcodeZone" mode is enabled, the barcode result will be more accurate but will cost more time.
 * @sa localizationAlgorithmPriority
 */


@property (nonatomic, assign) NSInteger maxBarcodeCount;
/**< Sets the maximum number of barcodes to read. This will limit the number of barcodes returned by library.
 * @par Value range:
 * 		[1,0x7fffffff]
 * @par Default value:
 * 		0x7fffffff
 * @par Remarks:
 *		If you want to limit the numbers of barcodes, you can set it to the corresponding value. It will stop localization and decoding once the maximum number is reached.
 */


@property (nonatomic, assign) BarcodeInvert barcodeInvert;
/**< Sets the barcode invert mode which decides whether to invert colour before binarization. 
 * @par Value range:
 * 		BarcodeInvertDarkOnLight, BarcodeInvertLightOnDark
 * @par Default value:
 * 		BarcodeInvertDarkOnLight
 * @par Remarks:
 *		This mode is designed to fit the scenarios with a light barcode located on a dark background. For example, a white QR on a sheet of black paper. 
 *		If the value is BarcodeInvertDarkOnLight, it will work better for dark barcodes on a light background; If the value is BarcodeInvertLightOnDark, it will work better for light barcodes on a dark background. 
 * @sa BarcodeInvert
 */


@property (nonatomic, assign) NSInteger scaleDownThreshold;
/**< Sets the threshold value an image can be scaled down to. If the shorter edge size is larger than the given value, the library will calculate the required height and width of the barcode image and shrink the image to that size before localization. Otherwise, it will perform barcode localization on the original image.
 * @par Value range:
 * 		[512,0x7fffffff]
 * @par Default value:
 * 		2300
 * @par Remarks:
 *		If you have an image whose shorter edge size is larger than the given value and the barcode is a small part on it, you can set this value to be larger than the shorter edge of this image.
 *		If you have an image whose shorter edge size is larger than the given value and the barcode is clear and big, you can set this value to a smaller one than the default value.
 */


@property (nonatomic, assign) NSInteger grayEqualizationSensitivity;
/**< Sets the sensitivity used for gray equalization. May cause adverse effect on images with a high level ofcontrast. The higher the value, the more likely gray equalization will be activated.
 * @par Value range:
 * 		[0,9]
 * @par Default value:
 * 		0
 * @par Remarks:
 *		If you have an image with a low level of contrast,  you can set the property to a larger value. If the value is set to 0, gray equalization will be disabled. If the value is set to 9, gray equalization will be activated.
 *		For better accuracy for images with low camparison, set this property to 9. 
 */


@property (nonatomic, assign) NSInteger enableFillBinaryVacancy;
/**< Sets whether to enable fill binary vacancy. 
 * @par Value range:
 * 		0, 1 (0 - disable, 1 - enable)
 * @par Default value:
 * 		1
 * @par Remarks:
 *		For barcodes with a large module size there might be a vacant area in the position detection pattern after binarization which may result in a decoding failure. Setting this to true will fill in the vacant area with black and may help to decode it successfully.
 *		Better accuracy for images with a large module size. 
 */


@property (nonatomic, assign) ColourImageConvert colourImageConvert;
/**< Sets whether to convert colour images to grayscale before processing.
 * @par Value range:
 * 		ColourImageConvertAuto, ColourImageConvertGrayScale
 * @par Default value:
 * 		ColourImageConvertAuto
 * @par Remarks:
 *		If you need to decode the barcode in the region pre-detection mode, it works better with the value ColourImageConvertAuto. There are no effects to the results. It will pass the original image for if you set it to ColourImageConvertAuto and the gray-scale image if you set it otherwise. 
 * @sa ColourImageConvert
 */


@property (nonatomic, nonnull) NSString * reserved;
/**< Reserved memory for struct. The length of this array indicates the size of the memory reserved for this struct.*/


@property (nonatomic, assign) NSInteger expectedBarcodeCount;
/**< Sets the expected number of barcodes to read for each image (or each region of the image if you specified barcode regions).
 * @par Value range:
 * 		[0,0x7fffffff]
 * @par Default value:
 * 		0
 * @par Remarks:
 * 		- 0: means Unknown and it will find at least one barcode.
 *
 * 		- 1: try to find one barcode. If one barcode is found, the library will stop the localization process and perform barcode decoding.
 *
 * 		- n: try to find n barcodes. If the library only finds m (m<n) barcode, it will try different algorithms till n barcodes are found or all algorithms are used.
 *
 * 		The value of ExpectedBarcodesCount must be less than or equal to the value of MaxBarcodesCount. To ensure the best performance, the value of AntiDamageLevel is suggested to be set to 9 if the ExpectedBarcodesCount is set to 0 or 1; otherwise, the value of AntiDamageLevel is suggested to be set to 7.
 *		When AntiDamageLevel is larger than 7, the bigger ExpectedBarcodesCount you set, the more localization algorithms will be used which leads to a higher accuracy with slower performance. 
 * @sa maxBarcodeCount antiDamageLevel
 */



@property (nonatomic, assign) NSInteger binarizationBlockSize;
/**< Sets the block size for the process of binarization. Block size refers to the size of a pixel neighborhood used to calculate a threshold value for the pixel.
 * @par Value range:
 * 		[0,1000]
 * @par Default:
 * 		0
 * @par Remarks:
 * 		- 0: the block size used for binarization will be set to a value which is calculated automatically.
 * 
 * 		- N:
 * 		 - 1 <= N <= 3: the block size used for binarization will be set to 3.
 * 		 - N > 3: the block size used for binarization will be set to N.
 *
 *		An appropriate value for mBinarizationBlockSize can help generate a high quality binary image to increase the accuracy of barcode localization.  
 */

@end

/**
 * @}
 */

/*--------------------------------------------------------------------*/

/**
 * Stores the extended result including the format, the bytes, etc.
 */
@interface ExtendedResult: NSObject


@property (nonatomic, assign) ResultTextType resultType;
/**< Extended result type */

@property (nonatomic, assign) BarcodeType barcodeType;
/**< Barcode type */

@property (nonatomic, assign) NSInteger confidence;
/**< The confidence of the result */

@property (nonatomic, nullable) NSData* bytes;
/**< The content in a byte array */

@end

/*--------------------------------------------------------------------*/


/**
 * Stores the localization result including the boundary, the angle, the page number, the region name, etc.
 */ 
@interface LocalizationResult: NSObject

@property (nonatomic, assign) TerminateStatus terminateStatus;
/**< The stage of localization result. */

@property (nonatomic, assign) BarcodeType barcodeType;
/**< Barcode type. */

@property (nonatomic, assign) NSInteger angle;
/**< The angle of a barcode. Values range from 0 to 360. */

@property (nonatomic, nullable) NSArray* resultPoints;
/**< The vetices' (x,y) coordinates information of the barcode region. */

@property (nonatomic, assign) NSInteger moduleSize;
/**< The barcode module size (the minimum bar width in pixel) */

@property (nonatomic, assign) NSInteger pageNumber;
/**< The page number the barcode located in. The index is 0-based. */

@property (nonatomic, nullable) NSString* regionName;
/**< The region name the barcode located in. */

@property (nonatomic, nullable) NSString* documentName;
/**< The document name. */

@property (nonatomic, nullable) NSArray<ExtendedResult*>* extendedResults;
/**< The extended result array */

@end

/*--------------------------------------------------------------------*/

/**
 * Stores the text result including the format, the text, the bytes, the localization result etc.
 */
@interface TextResult : NSObject

@property (nonatomic, assign) BarcodeType barcodeFormat;
/**< The barcode format */

@property (nonatomic, nullable) NSString* barcodeFormatString;
/**< Barcode type as string */

@property (nonatomic, nullable) NSString* barcodeText;
/**< The barcode text, ends by '\0' */

@property (nonatomic, nullable) NSData* barcodeBytes;
/**< The barcode content in a byte array */

@property (nonatomic, nullable) LocalizationResult* localizationResult;
/**< The corresponding localization result */

@end


/*--------------------------------------------------------------------*/


/**
* Defines a class that provides functions for working with extracting barcode data. 
* 
* Four methods are now supported for editing runtime settings - reset, initialize, append, update.
* - Reset runtime settings: reset all parameters in runtime setting to default value.
* 
* - Initialize with template: reset runtime settings firstly and replace all parameters in runtime setting with the values specified in given template regardless of the current runtime settings.
* 
* - Append template to runtime settings: append template and update runtime settings; the conflicting values will be assigned by the rules shown in PublicSettings.
* 
* - Update with struct: update current runtime settings by the values specified in given struct directly; the parameter not be defined in struct will remain its original value.
* 
* 
* @par References
* More information about public parameters and template file can be found in file DBR_Developer's_Guide.pdf.
* 
* 
* @sa PublicSettings
*/

@interface DynamsoftBarcodeReader: NSObject

 /**
  * Stores the license used in DynamsoftBarcodeReader.
  */
@property (nonatomic, nonnull) NSString* license;


/**
 * @name Basic Funcitons
 * @{
 */


/**
 * Initialization of DynamsoftBarcodeReader.
 *
 * @return The instance of DynamsoftBarcodeReader.
 *
 * @par Remark 
 *		If you initialize DynamsoftBarcodeReader by this method without license, the decoding results maybe unreliable.
 */
- (instancetype _Nonnull)init;
 
 /**
  * Initialization of DynamsoftBarcodeReader with license.
  *
  * @param [in] license The license key.
  *
  * @return The instance of DynamsoftBarcodeReader.
  */
- (instancetype _Nonnull)initWithLicense:(NSString* _Nonnull)license NS_DESIGNATED_INITIALIZER;

/**
 * Initializes barcode reader license and connects to the specified server for online verification.
 * 
 * @param [in] licenseSeServer The name/IP of the license server.		   
 * @param [in] licenseKey The license key of Barcode Reader.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @return The instance of DynamsoftBarcodeReader.
 */
- (instancetype _Nonnull)initWithLicenseFromServer:(NSString* _Nullable)licenseSeServer licenseKey:(NSString* _Nonnull)licenseKey error:(NSError * _Nullable * _Nullable)error NS_DESIGNATED_INITIALIZER;

/**
 * Outputs the license content as an encrypted string from the license server to be used for offline license verification.
 *
 * @return The output string which stores the contents of license.
 *
 */	
- (NSString *_Nullable)outputLicenseToString:(NSError* _Nullable * _Nullable)error;

/**
 * Gets current settings and save it into a struct.
 *
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @return A PublicSettings storing current runtime settings.
 *
 */
- (PublicSettings* _Nullable)getRuntimeSettings:(NSError* _Nullable * _Nullable)error;

/**
 * Update runtime settings with a given struct.
 *
 * @param [in] settings The struct of template settings.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 */
- (void)updateRuntimeSettings:(PublicSettings* _Nonnull)settings
                        error:(NSError* _Nullable * _Nullable)error;
/**
 * Resets all parameters to default values.
 *
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 */
- (void)resetRuntimeSettings:(NSError* _Nullable * _Nullable)error;


/**
 * Decodes barcode from an image file encoded as a base64 string.
 *
 * @param [in] base64 A base64 encoded string that represents an image.
 * @param [in] templateName The template name.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @return All barcode text results decoded successfully.
 *
 */
- (NSArray<TextResult*>* _Nullable)decodeBase64:(NSString* _Nonnull)base64
                                   withTemplate:(NSString* _Nonnull)templateName
                                          error:(NSError* _Nullable * _Nullable)error;

/**
 * Decodes barcodes from an image file in memory.
 *
 * @param [in] image The image file in memory.
 * @param [in] templateName The template name.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @return All barcode text results decoded successfully.
 */
- (NSArray<TextResult*>* _Nullable)decodeImage:(UIImage* _Nonnull)image
                                  withTemplate:(NSString* _Nonnull)templateName
                                         error:(NSError* _Nullable * _Nullable)error;

/**
 * Decodes barcodes from the memory buffer containing image pixels in defined format.
 *
 * @param [in] buffer The array of bytes which contain the image data.
 * @param [in] width The width of the image in pixels.
 * @param [in] height The height of the image in pixels.
 * @param [in] stride The stride of the image (also called scan width).
 * @param [in] format The image pixel format used in the image byte array.
 * @param [in] templateName The template name.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @return All barcode text results decoded successfully.
 */
- (NSArray<TextResult*>* _Nullable)decodeBuffer:(NSData* _Nonnull)buffer
                                      withWidth:(NSInteger)width
                                         height:(NSInteger)height
                                         stride:(NSInteger)stride
                                         format:(ImagePixelType)format
                                   templateName:(NSString* _Nonnull)templateName
                                          error:(NSError* _Nullable * _Nullable)error;


 /**
  * Decodes barcode in a specified image file with its path.
  *
  * @param [in] name The local path of the file.
  * @param [in] templateName The template name.
  * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
  *
  * @return All barcode text results decoded successfully.
  */
- (NSArray<TextResult*>* _Nullable)decodeFileWithName:(NSString* _Nonnull)name
                                         templateName:(NSString* _Nonnull)templateName
                                                error:(NSError* _Nullable * _Nullable)error;

 /**
  * Gets all localization barcode results. It contains all recognized barcodes and unrecognized barcodes.
  *
  * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
  *
  * @return All barcodes have been localized. If no barcodes is localized, an array with length 0 will be returned.
  *
  */
- (NSArray<LocalizationResult*>* _Nullable)allLocalizationResults:(NSError* _Nullable * _Nullable)error;


/**
 * @}
 * @name Advanced Functions
 * @{
 */

/**
 * Gets the parameter templates name array.
 *
 * @return The template name array.
 *
 */
- (NSArray<NSString*>* _Nullable)allParameterTemplateNames;

/**
 * Initialize runtime settings with the settings in given JSON file.
 *
 * @param [in] fileName The path of the settings file.
 * @param [in] conflictMode The parameter setting mode, which decides to inherit parameters from
 * 			  previous template setting or overwrite previous settings and replace by new template.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 * 
 * @sa DynamsoftBarcodeReader PublicSettings
 */
- (void)initRuntimeSettingsWithFile:(NSString* _Nonnull)fileName
                       conflictMode:(DBRConflictMode)conflictMode
	                          error:(NSError* _Nullable * _Nullable)error;

/**
 * Initialize runtime settings with the settings in given JSON string.
 *
 * @param [in] content A JSON string that represents the content of the settings.
 * @param [in] conflictMode The parameter setting mode, which decides to inherit parameters from
 * 			  previous template setting or overwrite previous settings and replace by new template.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @sa DynamsoftBarcodeReader PublicSettings
 */
- (void)initRuntimeSettingsWithString:(NSString* _Nonnull)content
						  conflictMode:(DBRConflictMode)conflictMode
								 error:(NSError* _Nullable * _Nullable)error;

/**
 * Append a new template file to current runtime settings.
 *
 * @param [in] fileName The path of the settings file.
 * @param [in] conflictMode The parameter setting mode, which decides to inherit parameters from
 * 			  previous template setting or overwrite previous settings and replace by new template.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @sa DynamsoftBarcodeReader PublicSettings
 */
- (void)appendTplFileToRuntimeSettings:(NSString * _Nonnull)fileName
					      conflictMode:(DBRConflictMode)conflictMode
								 error:(NSError * _Nullable *_Nullable)error;

/**
 * Append a new template string to current runtime settings.
 *
 * @param [in] content A JSON string that represents the content of the settings.
 * @param [in] conflictMode The parameter setting mode, which decides to inherit parameters from
 * 			  previous template setting or overwrite previous settings and replace by new template.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @sa DynamsoftBarcodeReader PublicSettings
 */
- (void)appendTplStringToRuntimeSettings:(NSString * _Nonnull)content
							conflictMode:(DBRConflictMode)conflictMode
								   error:(NSError *_Nullable *_Nullable)error;

/**
 * Outputs runtime settings to a string.
 *
 * @param [in] settingsName A unique name for declaring current runtime settings.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @return The output string which stores the contents of current settings. 
 *
 */
- (NSString *_Nullable)outputSettingsToString:(NSString*_Nonnull)settingsName 
                                        error:(NSError* _Nullable * _Nullable)error;

/**
 * Outputs runtime settings and save it into a settings file (JSON file).
 *
 * @param [in] filePath The output file path which stores current settings.
 * @param [in] settingsName A unique name for declaring current runtime settings.
 * 
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 */
- (void)outputSettingsToFile:(NSString *_Nullable)filePath 
				settingsName:(NSString*_Nonnull)settingsName 
					error:(NSError*_Nullable *_Nullable)error;

/**
 * @}
 * @name Compatible Functions
 * @{
 */

/**
 * Ensure compatibility with earlier versions. It is functionally equivalent to appendTplStringToRuntimeSettings with conflict mode DBRECM_Overwrite as default.
 *
 * @deprecated appendParameterTemplate
 *
 * @param [in] content A JSON string that represents the content of the settings.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @sa appendTplStringToRuntimeSettings
 */
-(void)appendParameterTemplate:(NSString* _Nonnull)content
	                                error:(NSError* _Nullable * _Nullable)error;

/**
 * Ensure compatibility with earlier versions. It is functionally equivalent to appendTplFileToRuntimeSettings with conflict mode DBRECM_Overwrite as default.
 *
 * @deprecated appendParameterTemplateFromFile
 *
 * @param [in] fileName The path of the settings file.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @sa appendTplFileToRuntimeSettings
 */ 
- (void)appendParameterTemplateFromFile:(NSString* _Nonnull)fileName
	                              error:(NSError* _Nullable * _Nullable)error;


/**
* Ensure compatibility with earlier versions. It is functionally equivalent to getRuntimeSettings.
*
* @deprecated templateSettingsWithName
*
* @param [in] templateName The template name.
* @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
*
* @return The struct of template settings.
*
*
* @sa getRuntimeSettings
*/
-(PublicSettings* _Nullable)templateSettingsWithName:(NSString* _Nonnull)templateName
	                                           error:(NSError* _Nullable * _Nullable)error;

/**
 * Ensure compatibility with earlier versions. It is functionally equivalent to initRuntimeSettingsWithString with conflict mode DBRECM_Overwrite as default.
 *
 * @deprecated loadSettings
 *
 * @param [in] content A JSON string that represents the content of the settings.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @sa initRuntimeSettingsWithString 
 */
-(void)loadSettings:(NSString* _Nonnull)content
	                     error:(NSError* _Nullable * _Nullable)error;

/**
 * Ensure compatibility with earlier versions. It is functionally equivalent to initRuntimeSettingsWithFile with conflict mode DBRECM_Overwrite as default.
 *
 * @deprecated loadSettingsFromFile
 *
 * @param [in] fileName The path of the settings file.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @sa initRuntimeSettingsWithFile
 */
-(void)loadSettingsFromFile:(NSString* _Nonnull)fileName
	                  error:(NSError* _Nullable * _Nullable)error;

/**
 * Ensure compatibility with earlier versions. It is functionally equivalent to updateRuntimeSettings.
 *
 * @deprecated setTemplateSettings
 *
 * @param [in] settings The struct of template settings.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @sa updateRuntimeSettings
 */
-(void)setTemplateSettings:(PublicSettings* _Nonnull)settings
	                 error:(NSError* _Nullable * _Nullable)error;




/**
 * @}
 */
@end

/**
 * @}
 * @}
 */
