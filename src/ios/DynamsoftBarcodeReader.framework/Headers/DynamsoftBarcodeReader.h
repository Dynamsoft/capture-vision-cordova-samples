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
 * @enum EnumErrorCode
 */
typedef NS_ENUM(NSInteger, EnumErrorCode) 
{
	/** Successful. */
	EnumErrorCode_OK                         = 0,
    
    /** Unknown error. */
    EnumErrorCode_Unknown                    = -10000,
	
	/** Not enough memory to perform the operation. */
    EnumErrorCode_No_Memory                  = -10001,
	
    /** Null pointer. */
    EnumErrorCode_Null_Pointer               = -10002,
	
	/** The license is invalid. */
    EnumErrorCode_License_Invalid            = -10003,
	
    /** The license has expired. */
    EnumErrorCode_License_Expired            = -10004,
	
    /** The file is not found. */
    EnumErrorCode_File_Not_Found             = -10005,
	
    /** The file type is not supported. */
    EnumErrorCode_Filetype_Not_Supported     = -10006,
	
	/** The BPP(Bits per pixel) is not supported. */
    EnumErrorCode_BPP_Not_Supported          = -10007,
	
    /** The index is invalid. */
    EnumErrorCode_Index_Invalid              = -10008,
	
	/** The barcode format is invalid. */
    EnumErrorCode_Barcode_Format_Invalid     = -10009,
	
	/** The input region value parameter is invalid. */
    EnumErrorCode_Custom_Region_Invalid      = -10010,
	
    /** The maximum barcode number is invalid. */
    EnumErrorCode_Max_Barcode_Number_Invalid = -10011,
	
	/** Failed to read the image. */
    EnumErrorCode_Image_Read_Failed          = -10012,

	/** Failed to read the TIFF image. */
    EnumErrorCode_TIFF_Read_Failed           = -10013,

	/** The QR Code license is invalid. */
    EnumErrorCode_QR_License_Invalid         = -10016,

	/** The 1D Barcode license is invalid. */
    EnumErrorCode_1D_Lincese_Invalid         = -10017,

	/** The DIB(Device-independent bitmaps) buffer is invalid. */
    EnumErrorCode_DIB_Buffer_Invalid         = -10018,

	/** The PDF417 license is invalid. */
    EnumErrorCode_PDF417_License_Invalid     = -10019,

	/** The DATAMATRIX license is invalid. */
    EnumErrorCode_Datamatrix_License_Invalid = -10020,
	
	/** Failed to read the PDF file. */
    EnumErrorCode_PDF_Read_Failed            = -10021,

	/** The PDF DLL is missing. */
    EnumErrorCode_PDF_DLL_Missing            = -10022,

	/** The page number is invalid. */
    EnumErrorCode_Page_Number_Invalid        = -10023,

	/** The custom size is invalid. */
    EnumErrorCode_Custom_Size_Invalid        = -10024,

	/** The custom module size is invalid. */
    EnumErrorCode_Custom_Modulesize_Invalid  = -10025,

	/** Recognition timeout. */
    EnumErrorCode_Recognition_Timeout        = -10026,

	/** Failed to parse json string. */
    EnumErrorCode_Json_Parse_Failed          = -10030,

	/** The value type is invalid. */
    EnumErrorCode_Json_Type_Invalid          = -10031,

	/** The key is invalid. */
    EnumErrorCode_Json_Key_Invalid           = -10032,

	/** The value is invalid or out of range. */
    EnumErrorCode_Json_Value_Invalid         = -10033,

	/** The mandatory key "Name" is missing. */
    EnumErrorCode_Json_Name_Key_Missing      = -10034,

	/** The value of the key "Name" is duplicated. */
    EnumErrorCode_Json_Name_Value_Duplicated = -10035,

	/** The template name is invalid. */
    EnumErrorCode_Template_Name_Invalid      = -10036,

	/** The name reference is invalid. */
    EnumErrorCode_Json_Name_Reference_Invalid = -10037,

	/**The parameter value is invalid or out of range. */
    EnumErrorCode_Parameter_Value_Invalid    = -10038,

	/**The domain of your current site does not match the domain bound in the current product key. */
    EnumErrorCode_Domain_Not_Matched         = -10039,

	/**The reserved info does not match the reserved info bound in the current product key. */
    EnumErrorCode_ReservedInfo_Not_Matched   = -10040,

	/** The AZTEC license is invalid. */
    EnumErrorCode_AZTEC_License_Invalid      = -10041,

    /** The License DLL is missing. */    
    EnumErrorCode_License_Dll_Missing        = -10042,

    /** The license key is not match the license file. */    
    EnumErrorCode_Licensekey_Not_Matched     = -10043,

    /** Failed to request the license file. */    
    EnumErrorCode_Requested_Failed           = -10044,

    /** Failed to init the license. */    
    EnumErrorCode_License_Init_Failed        = -10045,
    
    /** Failed to start framedecode */
    EnumErrorCode_Patchcode_License_Invalid   = -10046,

	/**The Postal code license is invalid. */
    EnumErrorCode_Postalcode_License_Invalid   = -10047,

	/**The DPM license is invalid. */
    EnumErrorCode_DPM_License_Invalid   = -10048,

	/**The frame decoding thread is already existed. */
    EnumErrorCode_Frame_Decoding_Thread_Exists   = -10049,

	/**Failed to stop the frame decoding thread. */
    EnumErrorCode_Stop_Decoding_Thread_Failed   = -10050,

	/**Failed to set mode's argument. */
    EnumErrorCode_Set_Mode_Argument_Error       = -10051,

	/**The license content is invalid. */
    EnumErrorCode_Licnse_Content_Invalid        = -10052,

	/**The license key is invalid. */
    EnumErrorCode_License_Key_Invalid           = -10053,

	/**The device number in the license key runs out. */
    EnumErrorCode_License_Device_Runs_Out       = -10054 
};

/**
 * Describes the error codes.
 * @enum DLSErrorCode
 */
typedef NS_ENUM(NSInteger, DLSErrorCode) 
{
    
    /**Common Error from Dynamsoft license server. */
    DLSErrorCode_CommonError                = -20000
    
};

/**
 * Describes the type of the barcode. All the formats can be combined, such as BF_CODE_39 | BF_CODE_128.
 * @enum EnumBarcodeFormat
 */
typedef NS_OPTIONS(NSInteger, EnumBarcodeFormat) 
{

	/** Code 39 */
    EnumBarcodeFormatCODE39     		 = 1 << 0,
	
	/** Code 128 */
    EnumBarcodeFormatCODE128    		 = 1 << 1,

	/** Code 93 */
    EnumBarcodeFormatCODE93     		 = 1 << 2,

	/** Codabar */
    EnumBarcodeFormatCODABAR    		 = 1 << 3,

	/** ITF */
    EnumBarcodeFormatITF        		 = 1 << 4,

	/** EAN-13 */
    EnumBarcodeFormatEAN13      		 = 1 << 5,

	/** EAN-8 */
    EnumBarcodeFormatEAN8       		 = 1 << 6,

	/** UPC-A */
    EnumBarcodeFormatUPCA       		 = 1 << 7,

	/** UPC-E */
    EnumBarcodeFormatUPCE       		 = 1 << 8,

	/** Industrial 2 of 5 */
    EnumBarcodeFormatINDUSTRIAL 		 = 1 << 9,

    /** CODE39 Extended */
    EnumBarcodeFormatCODE39EXTENDED 	 = 1 << 10,

	/** PDF417 */
    EnumBarcodeFormatPDF417     		 = 1 << 25,

	/** QRCode */
    EnumBarcodeFormatQRCODE     		 = 1 << 26,

	/** DataMatrix */
    EnumBarcodeFormatDATAMATRIX 		 = 1 << 27,

	/** AZTEC */
    EnumBarcodeFormatAZTEC       		 = 1 << 28,

	/** USPS Intelligent Mail. Not supported yet. */
    EnumBarcodeFormatUSPSINTELLIGENTMAIL = 1 << 20,

	/** PostNet.Not supported yet. */
	EnumBarcodeFormatPOSTNET 			 = 1 << 21,

	/** Palnet.Not supported yet. */
	EnumBarcodeFormatPLANET 			 = 1 << 22,

	/** AustralianPost.Not supported yet. */
	EnumBarcodeFormatAUSTRALIANPOST 	 = 1 << 23,

	/** UKRoyalMail.Not supported yet. */
	EnumBarcodeFormatUKROYALMAIL 		 = 1 << 24,

	/** PatchCode.Not supported yet. */
	EnumBarcodeFormatPATCHCODE 			 = 1 << 16,

    /** Combined value of BF_USPSINTELLIGENTMAIL, BF_POSTNET, BF_PLANET, BF_AUSTRALIANPOST, BF_UKROYALMAIL. Not supported yet. */
    EnumBarcodeFormatPOSTALCODE = EnumBarcodeFormatUSPSINTELLIGENTMAIL | EnumBarcodeFormatPOSTNET |
                            	  EnumBarcodeFormatPLANET | EnumBarcodeFormatAUSTRALIANPOST |
                            	  EnumBarcodeFormatUKROYALMAIL,

	/** Combined value of BF_CODABAR, BF_CODE_128, BF_CODE_39, BF_CODE_39_Extended, BF_CODE_93, BF_EAN_13, BF_EAN_8, INDUSTRIAL_25, BF_ITF, BF_UPC_A, BF_UPC_E; */
    EnumBarcodeFormatONED       = EnumBarcodeFormatCODE39 | EnumBarcodeFormatCODE128 |
                            	  EnumBarcodeFormatCODE93 | EnumBarcodeFormatCODABAR |
                            	  EnumBarcodeFormatITF    | EnumBarcodeFormatEAN13   |
                            	  EnumBarcodeFormatEAN8   | EnumBarcodeFormatUPCA    |
                            	  EnumBarcodeFormatUPCE   | EnumBarcodeFormatINDUSTRIAL | EnumBarcodeFormatCODE39EXTENDED,

	/** All supported formats */
    EnumBarcodeFormatALL        = EnumBarcodeFormatONED   | EnumBarcodeFormatPDF417  |
                            	  EnumBarcodeFormatQRCODE | EnumBarcodeFormatDATAMATRIX |
                            	  EnumBarcodeFormatAZTEC,

};

/** 
* Describes the image pixel format. 
* @enum EnumImagePixelFormat
*/
typedef NS_ENUM(NSInteger, EnumImagePixelFormat) 
{

	/** 0:Black, 1:White */
    EnumImagePixelFormatBinary         = 0,

	/** 0:White, 1:Black */
    EnumImagePixelFormatBinaryInverted = 1,

	/** 8bit gray */
    EnumImagePixelFormatGrayScaled     = 2,

	/** NV21 */
    EnumImagePixelFormatNV21 		   = 3,

	/** 16bit */
    EnumImagePixelFormatRGB_565 	   = 4,

	/** 16bit */
    EnumImagePixelFormatRGB_555 	   = 5,

	/** 24bit */
    EnumImagePixelFormatRGB_888 	   = 6,

	/** 32bit */
    EnumImagePixelFormatARGB_8888      = 7,

    /** 48bit */
    EnumImagePixelFormatRGB_161616     = 8,

    /** 64bit */
    EnumImagePixelFormatARGB_16161616  = 9

};

/*
* Describes the type of the barcode.
* @enum EnumBarcodeComplementMode
*/
typedef NS_ENUM(NSInteger, EnumBarcodeComplementMode)
{
	/** Not supported yet.*/
	EnumBarcodeComplementModeAuto 	 = 0x01,

	/** Complements the barcode using the general algorithm.*/
	EnumBarcodeComplementModeGeneral = 0x02,

	/**Skip the barcode complement. */
	EnumBarcodeComplementModeSkip 	 = 0x00
};

/*
* Describes the barcode colour mode.
* @enum EnumBarcodeColourMode
*/
typedef NS_ENUM(NSInteger, EnumBarcodeColourMode)
{
	/** Dark items on the light background. */
	EnumBarcodeColourModeDarkOnLight 				= 0x01,

	/** Light items on the dark background. Not supported yet. */
	EnumBarcodeColourModeLightOnDark 				= 0x02,

	/** Dark items on the dark background. Not supported yet. */
	EnumBarcodeColourModeDarkOnDark 				= 0x04,

	/** Light items on the light background. Not supported yet. */
	EnumBarcodeColourModeLightOnLight 				= 0x08,

	/** The background is mixed by dark and light. Not supported yet. */
	EnumBarcodeColourModeDarkLightMixed 			= 0x10,

	/** Dark on light items on the dark background */
	EnumBarcodeColourModeDarkOnLightDarkSurrounding = 0x20,

	/** Skip the barcode colour operation.  */
	EnumBarcodeColourModeSkip 						= 0x00
};

/*
* Describes the binarization mode.
* @enum EnumBinarizationMode
*/
typedef NS_ENUM(NSInteger, EnumBinarizationMode)
{
	/** Not supported yet. */
	EnumBinarizationModeAuto 	   = 0x01,

	/** Binarizes the image based on the local block. */
	EnumBinarizationModeLocalBlock = 0x02,

	/** Skip the binarization. */
	EnumBinarizationModeSkip       = 0x00
};

/*
* Describes the colour clustering mode.\
* @enum EnumColourClusteringMode
*/
typedef NS_ENUM(NSInteger, EnumColourClusteringMode)
{
	/** Not supported yet. */
	EnumColourClusteringModeAuto 	   = 0x01,

	/** Clusters colours using the general algorithm based on HSV. */
	EnumColourClusteringModeGeneralHSV = 0x02,

	/** Skip the colour clustering. */
	EnumColourClusteringModeSkip 	   = 0x00
};

/*
* Describes the colour conversion mode.	
* @enum EnumColourConversionMode
*/
typedef NS_ENUM(NSInteger, EnumColourConversionMode)
{
	/** Converts a colour image to a grayscale image using the general algorithm. */
	EnumColourConversionModeGeneral = 0x01,

	/** Skip the colour conversion. */
	EnumColourConversionModeSkip 	= 0x00
};

/*
* Describes the DPM code reading mode.
* @enum EnumDPMCodeReadingMode
*/
typedef NS_ENUM(NSInteger, EnumDPMCodeReadingMode)
{
	/** Not supported yet. */
	EnumDPMCodeReadingModeAuto    = 0x01,

	/** Reads DPM code using the general algorithm. */
	EnumDPMCodeReadingModeGeneral = 0x02,

	/** Skip the DPM code reading. */
	EnumDPMCodeReadingModeSkip    = 0x00
};

/*
* Describes the conflict mode.
* @enum EnumConflictMode
*/
typedef NS_ENUM(NSInteger, EnumConflictMode)
{
	/** Ignore new settings and inherit from previous settings. */
	EnumConflictModeIgnore    = 1,

	/** overwrite and replace by new settings. */
	EnumConflictModeOverwrite = 2
};

/*
* Describes the image preprocessing mode.
* @enum EnumImagePreprocessingMode
*/
typedef NS_ENUM(NSInteger, EnumImagePreprocessingMode)
{
	/** Not supported yet. */
	EnumImagePreprocessingModeAuto   	    = 0x01,

	/** Take the unpreprocessed image as the preprocessed result for further reference. */
	EnumImagePreprocessingModeGeneral 	    = 0x02,

	/** Preprocesses the image using the gray equalization algorithm. */
	EnumImagePreprocessingModeGrayEqualize  = 0x04,

	/** Preprocesses the image using the gray smoothing algorithm. */
	EnumImagePreprocessingModeGraySmooth    = 0x08,

	/** Preprocesses the image using the sharpening and smoothing algorithm. */
	EnumImagePreprocessingModeSharpenSmooth = 0x10,

	/** Skip the image preprocess */
	EnumImagePreprocessingModeSkip 			= 0x00
};

/*
* Describes the intermediate result type.
* @enum EnumIntermediateResultType
*/
typedef NS_ENUM(NSInteger, EnumIntermediateResultType)
{
	/** No intermediate result */
	EnumIntermediateResultTypeNoResult 					    = 0x00,

	/** Original image */
	EnumIntermediateResultTypeOriginalImage 			    = 0x01,

	/** Colour clustered image. Not supported yet. */
	EnumIntermediateResultTypeColourClusteredImage 		    = 0x02,

	/** Colour converted grayscale image */
	EnumIntermediateResultTypeColourConvertedGrayScaleImage = 0x04,

	/** Transformed grayscale image */
	EnumIntermediateResultTypeTransformedGrayScaleImage 	= 0x08,

	/** Predetected region */
	EnumIntermediateResultTypePredetectedRegion 			= 0x10,

	/** Preprocessed image */
	EnumIntermediateResultTypePreprocessedImage 			= 0x20,

	/** Binarized image */
	EnumIntermediateResultTypeBinarizedImage 				= 0x40,

	/** Text zone */
	EnumIntermediateResultTypeTextZone 						= 0x80,

	/** Contour */
	EnumIntermediateResultTypeContour 						= 0x100,

	/** Line segment */
	EnumIntermediateResultTypeLineSegment 					= 0x200,

	/** Form. Not supported yet. */
	EnumIntermediateResultTypeForm 							= 0x400,

	/** Segmentation block. Not supported yet. */
	EnumIntermediateResultTypeSegmentationBlock 			= 0x800,

	/** Typed barcode zone */
	EnumIntermediateResultTypeTypedBarcodeZone 				= 0x1000
};

/*
* Describes the localization mode.
* @enum EnumLocalizationMode
*/
typedef NS_ENUM(NSInteger, EnumLocalizationMode)
{
	/** Not supported yet. */
	EnumLocalizationModeAuto = 0x01,

	/** Localizes barcodes by searching connected blocks. This algorithm usually gives best result and it is recommended to set ConnectedBlocks to the highest priority. */
	EnumLocalizationModeConnectedBlocks = 0x02,

	/** Localizes barcodes by groups of contiguous black-white regions. This is optimized for QRCode and DataMatrix. */
	EnumLocalizationModeStatistics = 0x04,

	/** Localizes barcodes by searching for groups of lines. This is optimized for 1D and PDF417 barcodes.  */
	EnumLocalizationModeLines = 0x08,

	/** Localizes barcodes quickly. This mode is recommended in interactive scenario. */
	EnumLocalizationModeScanDirectly = 0x10,

	/** Skip the localization. */
	EnumLocalizationModeSkip = 0x00
};

/*
* Describes the QR Code error correction level.
* @enum EnumQRCodeErrorCorrectionLevel
*/
typedef NS_ENUM(NSInteger, EnumQRCodeErrorCorrectionLevel)
{
	/** Error Correction Level H (high) */	
	EnumQRCodeErrorCorrectionLevelErrorCorrectionH = 0,
	
	/** Error Correction Level L (low) */
	EnumQRCodeErrorCorrectionLevelErrorCorrectionL = 1,

	/** Error Correction Level M (medium-low) */
	EnumQRCodeErrorCorrectionLevelErrorCorrectionM = 2,

	/** Error Correction Level Q (medium-high) */
	EnumQRCodeErrorCorrectionLevelErrorCorrectionQ = 3
};

/*
* Describes the region predetection mode.
* @enum EnumRegionPredetectionMode
*/
typedef NS_ENUM(NSInteger, EnumRegionPredetectionMode)
{
	/** The library will automatically choose the algorithm to detect region. */
	EnumRegionPredetectionModeAuto 					= 0x01,

	/** Take the whole image as a region. */
	EnumRegionPredetectionModeGeneral 				= 0x02,

	/** Detects region using the general algorithm based on RGB colour contrast. */
	EnumRegionPredetectionModeGeneralRGBContrast 	= 0x04,

	/** Detects region using the general algorithm based on gray contrast. */
	EnumRegionPredetectionModeGeneralGrayContrast 	= 0x08,

	/** Detects region using the general algorithm based on HSV colour contrast. */
	EnumRegionPredetectionModeGeneralHSVContrast 	= 0x10,

	/** Skip the region detection. */
	EnumRegionPredetectionModeSkip 					= 0x00
};

/*
* Describes the deformation resisting mode.	
* @enum EnumDeformationResistingMode
*/
typedef NS_ENUM(NSInteger, EnumDeformationResistingMode)
{
	/** Not supported yet. */
	EnumDeformationResistingModeAuto 	= 0x01,

	/** Resists deformation using the general algorithm. */
	EnumDeformationResistingModeGeneral = 0x02,

	/** Skip the deformation resisting. */
	EnumDeformationResistingModeSkip 	= 0x00
};

/*
* Describes the extended result type. 
* @enum EnumResultType
*/
typedef NS_ENUM(NSInteger, EnumResultType) 
{
	/** Specifies the standard text. This means the barcode value. */
    EnumResultTypeStandardText 	= 0,

	/** Specifies the raw text. This means the text that includes start/stop characters, check digits, etc. */
    EnumResultTypeRawText 		= 1,

	/** Specifies all the candidate text. This means all the standard text results decoded from the barcode. */
    EnumResultTypeCandidateText = 2,

	/** Specifies the partial Text. This means part of the text result decoded from the barcode. */
    EnumResultTypePartialText 	= 3
};

/*
* Describes the terminate phase. 
* @enum EnumTerminatePhase
*/
typedef NS_ENUM(NSInteger, EnumTerminatePhase) 
{
	/** Exits the barcode reading algorithm after the region predetection is done. */
    EnumTerminatePhasePredetected 	 = 0x01,

	/** Exits the barcode reading algorithm after the region predetection and image pre-processing is done. */
    EnumTerminatePhasePreprocecessed = 0x02,

	/** Exits the barcode reading algorithm after the region predetection, image pre-processing and image binarization are done. */
    EnumTerminatePhaseBinarized 	 = 0x04,

	/** Exits the barcode reading algorithm after the region predetection, image pre-processing, image binarization and barcode localization are done. */
    EnumTerminatePhasesLocalized  	 = 0x08,

	/** Exits the barcode reading algorithm after the region predetection, image pre-processing, image binarization, barcode localization and barcode type determining are done. */
    EnumTerminatePhaseDetermined 	 = 0x10,

	/** Exits the barcode reading algorithm after the region predetection, image pre-processing, image binarization, barcode localization, barcode type determining and barcode recognition are done. */
    EnumTerminatePhaseRecognized 	 = 0x20
};

/*
* Describes the text assisted correction mode.
* @enum EnumTextAssistedCorrectionMode
*/
typedef NS_ENUM(NSInteger, EnumTextAssistedCorrectionMode)
{
	/** Not supported yet. */
	EnumTextAssistedCorrectionModeAuto 				= 0x01,

	/** The accompanying text will be used to verify the decoded barcode result. */
	EnumTextAssistedCorrectionModeVerifying 		= 0x02,

	/** The accompanying text will be used to verify and patch the decoded barcode result. */
	EnumTextAssistedCorrectionModeVerifyingPatching = 0x04,

	/** Skip the text assisted correction. */
	EnumTextAssistedCorrectionModeSkip 				= 0x00
};

/*
* Describes the text filter mode. 
* @enum EnumTextFilterMode
*/
typedef NS_ENUM(NSInteger, EnumTextFilterMode)
{
	/** Not supported yet. */
	EnumTextFilterModeAuto 			 = 0x01,

	/** Filters text using the general algorithm based on contour. */
	EnumTextFilterModeGeneralContour = 0x02,

	/** Skip the text filtering. */
	EnumTextFilterModeSkip 			 = 0x00
};

/*
* Describes the text result order mode.
* @enum EnumTextResultOrderMode
*/
typedef NS_ENUM(NSInteger, EnumTextResultOrderMode)
{
	/** Returns the text results in descending order by confidence. */
	EnumTextResultOrderModeConfidence = 0x01,

	/** Returns the text results in position order, from top to bottom, then left to right */
	EnumTextResultOrderModePosition   = 0x02,

	/** Returns the text results in alphabetical and numerical order by barcode format string. */
	EnumTextResultOrderModeFormat     = 0x04,

	/** Skip the ordering operation. */
	EnumTextResultOrderModeSkip       = 0x00
};

/*
* Describes the texture detection mode.
* @enum EnumTextureDetectionMode
*/
typedef NS_ENUM(NSInteger, EnumTextureDetectionMode)
{
	/** Not supported yet. */
	EnumTextureDetectionModeAuto = 0X01,

	/** Detects texture using the general algorithm. */
	EnumTextureDetectionModeGeneralWidthConcentration = 0X02,

	/** Skip the texture detection. */
	EnumTextureDetectionModeSkip = 0x00
};

/*
* Describes the grayscale transformation mode.
* @enum EnumGrayscaleTransformationMode
*/
typedef NS_ENUM(NSInteger, EnumGrayscaleTransformationMode)
{
	/** Transforms to the inverted grayscale for further reference. This value is recommand for light on dark images. */
	EnumGrayscaleTransformationModeInverted = 0x01,
	
	/** Keeps the original grayscale for further reference. This value is recommand for dark on light images. */
	EnumGrayscaleTransformationModeOriginal = 0x02,

	/** Skip the grayscale transformation. */
	EnumGrayscaleTransformationModeSkip 	= 0x00
};

/*
* Describes the result coordinate type.
* @enum EnumResultCoordinateType
*/
typedef NS_ENUM(NSInteger, EnumResultCoordinateType)
{
	/** Returns the coordinate in pixel value. */
	EnumResultCoordinateTypePixel 	   = 0x01,

	/** Returns the coordinate as a percentage. */
	EnumResultCoordinateTypePercentage = 0x02
};

/*
* Describes the intermediate result data type.
* @enum EnumIMResultDataType
*/
typedef NS_ENUM(NSInteger,EnumIMResultDataType)
{
	/**Specifies the ImageData */
	EnumIMResultDataTypeImage 				= 0x01,

	/**Specifies the Contour */
	EnumIMResultDataTypeContour 			= 0x02,
	
	/**Specifies the LineSegment */
	EnumIMResultDataTypeLineSegment 		= 0x04,

	/**Specifies the LocalizationResult */
    EnumIMResultDataTypeLocalizationResult 	= 0x08,
	
	/**Specifies the RegionOfInterest */
	EnumIMResultDataTypeREGIONOFINTEREST 	= 0x10
};

/**
 * @} defgroup Enum Enumerations
 */


/*--------------------------------------------------------------------*/

/**
 * @defgroup IOSInterface Class 
 * @{

/**
 * Stores the FurtherModes.
 */
@interface iFurtherModes : NSObject

/** Sets the mode and priority for colour categorization. Not supported yet..
*
* @par Value range:
* 	    Each array item can be any one of the ColourClusteringMode Enumeration items.
* @par Default value:
* 	    [CCM_SKIP,CCM_SKIP,CCM_SKIP,CCM_SKIP,CCM_SKIP,CCM_SKIP,CCM_SKIP,CCM_SKIP]
* @par Remarks:
*     The array index represents the priority of the item. The smaller index is, the higher priority is.
* @sa EnumColourClusteringMode
*/
@property (nonatomic, assign) NSArray* colourClusteringModes;

/** Sets the mode and priority for converting a colour image to a grayscale image.
*
* @par Value range:
* 	    Each array item can be any one of the ColourConversionMode Enumeration items.
* @par Default value:
* 	    [CICM_GENERAL,CICM_SKIP,CICM_SKIP,CICM_SKIP,CICM_SKIP,CICM_SKIP,CICM_SKIP,CICM_SKIP]
* @par Remarks:
*     The array index represents the priority of the item. The smaller index is, the higher priority is.
* @sa EnumColourConversionMode
*/
@property (nonatomic, assign) NSArray* colourConversionModes;

/** Sets the mode and priority for the grayscale image conversion.
*
* @par Value range:
* 	    Each array item can be any one of the GrayscaleTransformationMode Enumeration items
* @par Default value:
* 	    [GTM_ORIGINAL,GTM_SKIP,GTM_SKIP,GTM_SKIP,GTM_SKIP,GTM_SKIP,GTM_SKIP,GTM_SKIP]
* @par Remarks:
*     The array index represents the priority of the item. The smaller index is, the higher priority is.
* @sa EnumGrayscaleTransformationMode
*/
@property (nonatomic, assign) NSArray* grayscaleTransformationModes;

/** Sets the region pre-detection mode for barcodes search.
*
* @par Value range:
* 	    Each array item can be any one of the RegionPredetectionMode Enumeration items
* @par Default value:
* 	    [RPM_GENERAL,RPM_SKIP,RPM_SKIP,RPM_SKIP,RPM_SKIP,RPM_SKIP,RPM_SKIP,RPM_SKIP]
* @par Remarks:
*     The array index represents the priority of the item. The smaller index is, the higher priority is.
*     If the image is large and the barcode on the image is very small, it is recommended to enable region predetection to speed up the localization process and recognition accuracy.
* @sa EnumRegionPredetectionMode
*/
@property (nonatomic, assign) NSArray* regionPredetectionModes;

/** Sets the mode and priority for image preprocessing algorithms.
*
* @par Value range:
* 	    Each array item can be any one of the ImagePreprocessingMode Enumeration items
* @par Default value:
* 	    [IPM_GENERAL,IPM_SKIP,IPM_SKIP,IPM_SKIP,IPM_SKIP,IPM_SKIP,IPM_SKIP,IPM_SKIP]
* @par Remarks:
*     The array index represents the priority of the item. The smaller index is, the higher priority is.
* @sa EnumImagePreprocessingMode
*/
@property (nonatomic, assign) NSArray* imagePreprocessingModes;

/** Sets the mode and priority for texture detection.
*
* @par Value range:
* 	    Each array item can be any one of the TextureDetectionMode Enumeration items
* @par Default value:
* 	    [TDM_GENERAL_WIDTH_CONCENTRATION,TDM_SKIP,TDM_SKIP,TDM_SKIP,TDM_SKIP,TDM_SKIP,TDM_SKIP,TDM_SKIP]
* @par Remarks:
*     The array index represents the priority of the item. The smaller index is, the higher priority is.
* @sa EnumTextureDetectionMode
*/
@property (nonatomic, assign) NSArray* textureDetectionModes;

/** Sets the mode and priority for text filter.
*
* @par Value range:
* 	    Each array item can be any one of the TextFilterMode Enumeration items
* @par Default value:
* 	    [TFM_GENERAL_CONTOUR,TFM_SKIP,TFM_SKIP,TFM_SKIP,TFM_SKIP,TFM_SKIP,TFM_SKIP,TFM_SKIP]
* @par Remarks:
*     The array index represents the priority of the item. The smaller index is, the higher priority is.
*     If the image contains a lot of text, you can enable text filter to speed up the localization process.
* @sa EnumTextFilterMode
*/
@property (nonatomic, assign) NSArray* textFilterModes;

/** Sets the mode of text assisted correction for barcode decoding. Not supported yet.
*
* @par Value range:
* 	    Any one of the TextAssistedCorrectionMode Enumeration items
* @par Default value:
* 	    TACM_VERIFYING
* @sa EnumTextAssistedCorrectionMode
*/
@property (nonatomic, assign) EnumTextAssistedCorrectionMode textAssistedCorrectionMode;

/** Sets the mode and priority for DPM code reading. Not supported yet.
*
* @par Value range:
* 	    Each array item can be any one of the ColourConversionMode Enumeration items
* @par Default value:
* 	    [DPMCRM_SKIP,DPMCRM_SKIP,DPMCRM_SKIP,DPMCRM_SKIP,DPMCRM_SKIP,DPMCRM_SKIP,DPMCRM_SKIP,DPMCRM_SKIP]
* @par Remarks:
*     The array index represents the priority of the item. The smaller index is, the higher priority is.
* @sa EnumColourConversionMode
*/
@property (nonatomic, assign) NSArray* dpmCodeReadingModes;

/** Sets the mode and priority for deformation resisting. Not supported yet.
*
* @par Value range:
* 	    Each array item can be any one of the DeformationResistingMode Enumeration items
* @par Default value:
* 	    [DRM_SKIP,DRM_SKIP,DRM_SKIP,DRM_SKIP,DRM_SKIP,DRM_SKIP,DRM_SKIP,DRM_SKIP]
* @par Remarks:
*     The array index represents the priority of the item. The smaller index is, the higher priority is.
* @sa EnumDeformationResistingMode
*/
@property (nonatomic, assign) NSArray* deformationResistingModes;

/** Sets the mode and priority to complement the missing parts in the barcode. Not supported yet.
*
* @par Value range:
* 	    Each array item can be any one of the BarcodeComplementMode Enumeration items
* @par Default value:
* 	    [BCM_SKIP,BCM_SKIP,BCM_SKIP,BCM_SKIP,BCM_SKIP,BCM_SKIP,BCM_SKIP,BCM_SKIP]
* @par Remarks:
*     The array index represents the priority of the item. The smaller index is, the higher priority is.
* @sa EnumBarcodeComplementMode
*/
@property (nonatomic, assign) NSArray* barcodeComplementModes;

/** Sets the mode and priority for the barcode colour mode used to process the barcode zone.
*
* @par Value range:
* 	    Each array item can be any one of the BarcodeColourMode Enumeration items
* @par Default value:
* 	    [BICM_DARK_ON_LIGHT,BICM_SKIP,BICM_SKIP,BICM_SKIP,BICM_SKIP,BICM_SKIP,BICM_SKIP,BICM_SKIP]
* @par Remarks:
*     The array index represents the priority of the item. The smaller index is, the higher priority is.
* @sa EnumBarcodeColourMode
*/
@property (nonatomic, assign) NSArray* barcodeColourModes;

@end


/**
*Stores the region info.
*/
@interface iRegionDefinition : NSObject

/** The top-most coordinate or percentage of the region.
*
* @par Value range:
* 	    regionMeasuredByPercentage = 0, [0, 0x7fffffff]
* 	    regionMeasuredByPercentage = 1, [0, 100]
* @par Default value:
* 	    0
*/
@property (nonatomic, assign) NSInteger regionTop;

/** The left-most coordinate or percentage of the region.
*
* @par Value range:
* 	    regionMeasuredByPercentage = 0, [0, 0x7fffffff]
* 	    regionMeasuredByPercentage = 1, [0, 100]
* @par Default value:
* 	    0
*/
@property (nonatomic, assign) NSInteger regionLeft;

/** The right-most coordinate or percentage of the region.
*
* @par Value range:
* 	    regionMeasuredByPercentage = 0, [0, 0x7fffffff]
* 	    regionMeasuredByPercentage = 1, [0, 100]
* @par Default value:
* 	    0
*/
@property (nonatomic, assign) NSInteger regionRight;

/** The bottom-most coordinate or percentage of the region.
*
* @par Value range:
* 	    regionMeasuredByPercentage = 0, [0, 0x7fffffff]
* 	    regionMeasuredByPercentage = 1, [0, 100]
* @par Default value:
* 	    0
*/
@property (nonatomic, assign) NSInteger regionBottom;

/** Sets whether or not to use percentages to measure the Region size.
*
* @par Value range:
* 	    [0, 1]
* @par Default value:
* 	    0
* @par Remarks:
*     When itos set to 1, the values of Top, Left, Right, Bottom indicates the percentage (from 0 to 100). Otherwise, they refer to the coordinates.
*     0: not by percentage
*     1: by percentage
*/
@property (nonatomic, assign) NSInteger regionMeasuredByPercentage;

@end


/**
* Defines a struct to configure the barcode reading runtime settings.
* These settings are used to control the barcode recognition process such as which barcode types are to be decoded.
*
*/
@interface iPublicRuntimeSettings: NSObject

/** Sets the phase where the algorithm stops.
*
* @par Value range:
* 	    Any one of the TerminatePhase Enumeration items
* @par Default value:
* 	    TP_BARCODE_RECOGNIZED
* @par Remarks:
*	    When the recognition result is not desired, this parameter can be set to skip certain processing stages.
* @sa EnumTerminatePhase
*/
@property (nonatomic, assign) EnumTerminatePhase terminatePhase;

/** Sets the maximum amount of time (in milliseconds) that should be spent searching for a barcode per page. It does not include the time taken to load/decode an image (Tiff, PNG, etc) from disk into memory.
*
* @par Value range:
* 	    [0, 0x7fffffff]
* @par Default value:
* 	    10000
* @par Remarks:
*	    If you want to stop reading barcodes after a specified amount of time, you can use this parameter to set a timeout.
*/
@property (nonatomic, assign) NSInteger timeout;

/** Sets the number of threads the image processing algorithm will use to decode barcodes.
*
* @par Value range:
* 	    [1, 4]
* @par Default value:
* 	    4
* @par Remarks:
*	    By default, the library concurrently runs four different threads for decoding barcodes in order to keep a balance between speed and quality. For some devices (e.g. Raspberry Pi) that only use one core, you can set it to 1 for best speed. If you create BarcodeReader.
*/
@property (nonatomic, assign) NSInteger maxAlgorithmThreadCount;

/** Sets the number of barcodes expected to be detected for each image.
*
* @par Value range:
* 	    [0, 0x7fffffff]
* @par Default value:
* 	    0
* @par Remarks:
*	    0: means Unknown and it will find at least one barcode.
*	    1: try to find one barcode. If one barcode is found, the library will stop the localization process and perform barcode decoding.
*	    n: try to find n barcodes. If the library only finds m (m<n) barcode, it will try different algorithms till n barcodes are found or all algorithms are used.
*/
@property (nonatomic, assign) NSInteger expectedBarcodesCount;

/** Sets the formats of the barcode to be read. Barcode formats can be combined.
*
* @par Value range:
* 	    A combined value of BarcodeFormat Enumeration items
* @par Default value:
* 	    BF_ALL
* @par Remarks:
*	    If you already know the barcode type(s) before performing barcode reading, specifying the barcode type(s) to be read will speed up the recognition process.
* @sa EnumBarcodeFormat
*/
@property (nonatomic, assign) NSInteger barcodeFormatIds;

/** Sets the output image resolution.
*
* @par Value range:
* 	    [100, 600]
* @par Default value:
* 	    300
* @par Remarks:
*	    When you are trying to decode a PDF file using DecodeFile method, the library will convert the pdf file to image(s) first, then perform barcode recognition.
*/
@property (nonatomic, assign) NSInteger pdfRasterDPI;

/** Sets the threshold for the image shrinking.
*
* @par Value range:
* 	    [512, 0x7fffffff]
* @par Default value:
* 	    2300
* @par Remarks:
*	    If the shorter edge size is larger than the given value, the library will calculate the required height and width of the barcode image and shrink the image to that size before localization. Otherwise, it will perform barcode localization on the original image.
*/
@property (nonatomic, assign) NSInteger scaleDownThreshold;

/** Sets the mode and priority for binarization.
*
* @par Value range:
* 	    Each array item can be any one of the BinarizationMode Enumeration items
* @par Default value:
* 	    [BM_LOCAL_BLOCK,BM_SKIP,BM_SKIP,BM_SKIP,BM_SKIP,BM_SKIP,BM_SKIP,BM_SKIP]
* @par Remarks:
*     The array index represents the priority of the item. The smaller index is, the higher priority is.
* @sa EnumBinarizationMode
*/
@property (nonatomic, assign) NSArray* binarizationModes;

/** Sets the mode and priority for localization algorithms.
*
* @par Value range:
* 	    Each array item can be any one of the LocalizationMode Enumeration items
* @par Default value:
* 	    [LM_CONNECTED_BLOCKS,LM_SCAN_DIRECTLY,LM_STATISTICS,LM_LINES,LM_SKIP,LM_SKIP,LM_SKIP,LM_SKIP]
* @par Remarks:
*     The array index represents the priority of the item. The smaller index is, the higher priority is.
* @sa EnumLocalizationMode
*/
@property (nonatomic, assign) NSArray* localizationModes;

/** Sets the further modes.
*
*/
@property (nonatomic, nonnull) iFurtherModes* furtherModes;

/** Sets the degree of blurriness of the barcode.
*
* @par Value range:
* 	    [0, 9]
* @par Default value:
* 	    9
* @par Remarks:
*	    If you have a blurry image, you can set this property to a larger value. The higher value set, the more effort the library will spend to decode images, but it may also slow down the recognition process.
*/
@property (nonatomic, assign) NSInteger deblurLevel;

/** Sets which types of intermediate result to be kept for further reference. Intermediate result types can be combined.
*
* @par Value range:
* 	    A combined value of IntermediateResultType Enumeration items
* @par Default value:
* 	    0
* @sa EnumIntermediateResultType
*/
@property (nonatomic, assign) NSInteger intermediateResultTypes;

/** Specifies the format for the coordinates returned.
*
* @par Value range:
* 	    Any one of the ResultCoordinateType Enumeration items
* @par Default value:
* 	    RCT_PIXEL
* @sa EnumResultCoordinateType
*/
@property (nonatomic, assign) EnumResultCoordinateType resultCoordinateType;

/** Sets the mode and priority for the order of the text results returned.
*
* @par Value range:
* 	    Each array item can be any one of the TextResultOrderMode Enumeration items
* @par Default value:
* 	    [TROM_CONFIDENCE,TROM_POSITION,TROM_FORMAT,TROM_SKIP,TROM_SKIP,TROM_SKIP,TROM_SKIP,TROM_SKIP]
* @par Remarks:
*     The array index represents the priority of the item. The smaller index is, the higher priority is.
* @sa EnumTextResultOrderMode
*/
@property (nonatomic, assign) NSArray* textResultOrderModes;

/** Sets the region definition including the regionTop, regionLeft, regionRight, regionBottom and regionMeasuredByPercentage.
*
*/
@property (nonatomic, nonnull) iRegionDefinition* region;

/** Sets the range of barcode text length for barcodes search.
*
* @par Value range:
* 	    [0, 0x7fffffff]
* @par Default value:
* 	    0
* @par Remarks:
*     0: means no limitation on the barcode text length.
*/
@property (nonatomic, assign) NSInteger minBarcodeTextLength;

/** The minimum confidence of the result.
*
* @par Value range:
* 	    [0, 100]
* @par Default value:
* 	    0
* @par Remarks:
*     0: means no limitation on the confidence.
*/
@property (nonatomic, assign) NSInteger minResultConfidence;

@end


/**
* Stores the extended result.
*
*/
@interface iExtendedResult: NSObject

/** Extended result type */
@property (nonatomic, assign) EnumResultType resultType;

/** Barcode type */
@property (nonatomic, assign) EnumBarcodeFormat barcodeFormat;

/** Barcode type as string */
@property (nonatomic, nullable) NSString* barcodeFormatString;

/** The confidence of the result */
@property (nonatomic, assign) NSInteger confidence;

/** The content in a byte array */
@property (nonatomic, nullable) NSData* bytes;

/** The accompanying text content in a byte array */
@property (nonatomic, nullable) NSData* accompanyingTextBytes;

/** The deformation value */
@property (nonatomic, assign) NSInteger deformation;

/** One of the following: @ref QRCodeDetails, @ref PDF417Details, @ref DataMatrixDetails, @ref AztecDetails, @ref OneDCodeDetails */
@property (nonatomic, nullable) NSObject* detailedResult;

@end


/**
 * Stores the localization result including the boundary, the angle, the page number, the region name, etc.
 */ 
@interface iLocalizationResult: NSObject

/** The terminate phase of localization result. */
@property (nonatomic, assign) EnumTerminatePhase terminatePhase;

/** Barcode type. */
@property (nonatomic, assign) EnumBarcodeFormat barcodeFormat;

/** Barcode type as string */
@property (nonatomic, nullable) NSString* barcodeFormatString;

/** The array which stores the coordinates of four result points. */
@property (nonatomic, nullable) NSArray* resultPoints;

/** The angle of a barcode. Values range from 0 to 360. */
@property (nonatomic, assign) NSInteger angle;

/** The barcode module size (the minimum bar width in pixel) */
@property (nonatomic, assign) NSInteger moduleSize;

/** The page number the barcode located in. The index is 0-based. */
@property (nonatomic, assign) NSInteger pageNumber;

/** The region name the barcode located in. */
@property (nonatomic, nullable) NSString* regionName;

/** The document name. */
@property (nonatomic, nullable) NSString* documentName;

/** The coordinate type.*/
@property (nonatomic, assign) EnumResultCoordinateType resultCoordinateType;

/** The accompanying text content in a byte array */
@property (nonatomic, nullable) NSData* accompanyingTextBytes;

@end


/**
* Stores the text result
*
*/
@interface iTextResult : NSObject

/** The barcode format */
@property (nonatomic, assign) EnumBarcodeFormat barcodeFormat;

/** Barcode format as string */
@property (nonatomic, nullable) NSString* barcodeFormatString;

/** The barcode text, ends by '\0' */
@property (nonatomic, nullable) NSString* barcodeText;

/** The barcode content in a byte array */
@property (nonatomic, nullable) NSData* barcodeBytes;

/** The corresponding localization result */
@property (nonatomic, nullable) iLocalizationResult* localizationResult;

/** One of the following: @ref QRCodeDetails, @ref PDF417Details, @ref DataMatrixDetails, @ref AztecDetails, @ref OneDCodeDetails */
@property (nonatomic, nullable) NSObject* detailedResult;

/** The extended result array */
@property (nonatomic, nullable) NSArray<iExtendedResult*>* extendedResults;

@end


/**
* Stores the OneD code details
*
*/
@interface iOneDCodeDetails : NSObject

/** The barcode module size (the minimum bar width in pixel) */
@property (nonatomic, assign) NSInteger moduleSize;

/** The start chars in a byte array */
@property (nonatomic, nullable) NSData* startCharsBytes;

/** The stop chars in a byte array */
@property (nonatomic, nullable) NSData* stopCharsBytes;

/** The check digit chars in a byte array */
@property (nonatomic, nullable) NSData* checkDigitBytes;

@end


/**
* Stores the QRCode details
*
*/
@interface iQRCodeDetails : NSObject

/** The barcode module size (the minimum bar width in pixel) */
@property (nonatomic, assign) NSInteger moduleSize;

/** The row count of the barcode */
@property (nonatomic, assign) NSInteger rows;

/** The column count of the barcode */
@property (nonatomic, assign) NSInteger columns;

/** The error correction level of the barcode */
@property (nonatomic, assign) EnumQRCodeErrorCorrectionLevel errorCorrectionLevel;

/** The version of the QR Code */
@property (nonatomic, assign) NSInteger version;

/** Number of the models */
@property (nonatomic, assign) NSInteger model;

@end


/**
* Stores the PDF417 details
*
*/
@interface iPDF417Details : NSObject

@property (nonatomic, assign) NSInteger moduleSize;
/** The barcode module size (the minimum bar width in pixel) */

@property (nonatomic, assign) NSInteger rows;
/** The row count of the barcode */

@property (nonatomic, assign) NSInteger columns;
/** The column count of the barcode */

@property (nonatomic, assign) NSInteger errorCorrectionLevel;
/** The error correction level of the barcode */

@end


/**
* Stores the DataMatrix details
*
*/
@interface iDataMatrixDetails : NSObject

/** The barcode module size (the minimum bar width in pixel) */
@property (nonatomic, assign) NSInteger moduleSize;

/** The row count of the barcode */
@property (nonatomic, assign) NSInteger rows;

/** The column count of the barcode */
@property (nonatomic, assign) NSInteger columns;

/** The data region row count of the barcode */
@property (nonatomic, assign) NSInteger dataRegionRows;

/** The data region column count of the barcode */
@property (nonatomic, assign) NSInteger dataRegionColumns;

/** The data region count */
@property (nonatomic, assign) NSInteger dataRegionNumber;

@end


/**
* Stores the Aztec details
*
*/
@interface iAztecDetails : NSObject

/** The barcode module size (the minimum bar width in pixel) */
@property (nonatomic, assign) NSInteger moduleSize;

/** The row count of the barcode */
@property (nonatomic, assign) NSInteger rows;

/** The column count of the barcode */
@property (nonatomic, assign) NSInteger columns;

/** A negative number (-1, -2, -3, -4) specifies a compact Aztec code.
*   A positive number (1, 2, .. 32) specifies a normal (full-rang) Aztec code*/
@property (nonatomic, assign) NSInteger layerNumber;

@end


/**
* Stores the intermediate result
*
*/
@interface iIntermediateResult : NSObject

/**The total result count */
@property (nonatomic, assign) NSInteger resultsCount;

/**One of the following types: Array of @ref Contour, Array of @ref ImageData, Array of @ref LineSegment, Array of @ref LocalizationResult, Array of @ref RegionOfInterest */
@property (nonatomic, nonnull) NSObject* results;

/** Intermediate data Type */
@property (nonatomic, assign) EnumIMResultDataType dataType;

/** Intermediate Result Type */
@property (nonatomic, assign) EnumIntermediateResultType resultType;

/** The BarcodeComplementMode used when generating the current Intermediate result */
@property (nonatomic, assign) EnumBarcodeComplementMode barcodeComplementMode;

/** The array index of current used ColourClusteringMode in ColourClusteringModes setting */
@property (nonatomic, assign) NSInteger bcmIndex;

/** The DeformationResistingMode used when generating the current Intermediate result */
@property (nonatomic, assign) EnumDeformationResistingMode deformationResistingMode;

/** The array index of current used DeformationResistingMode in DeformationResistingModes setting */
@property (nonatomic, assign) NSInteger drmIndex;

/** The DPMCodeReadingMode used when generating the current Intermediate result */
@property (nonatomic, assign) EnumDPMCodeReadingMode dpmCodeReadingMode;

/** The array index of current used DPMCodeReadingMode in DPMCodeReadingModes setting */
@property (nonatomic, assign) NSInteger dpmcrmIndex;

/**The rotation matrix. */
@property (nonatomic, nonnull) NSArray* transformationMatrix;

/** The TextFilterMode used when generating the current Intermediate result */
@property (nonatomic, assign) EnumTextFilterMode textFilterMode;

/** The array index of current used TextFilterMode in TextFilterModes setting */
@property (nonatomic, assign) NSInteger tfmIndex;

/** The LocalizationMode used when generating the current Intermediate result */
@property (nonatomic, assign) EnumLocalizationMode localizationMode;

/** The array index of current used LocalizationMode in LocalizationModes setting */ 
@property (nonatomic, assign) NSInteger lmIndex;

/** The BinarizationMode used when generating the current Intermediate result */
@property (nonatomic, assign) EnumBinarizationMode binarizationMode;

/** The array index of current used BinarizationMode in BinarizationModes setting */
@property (nonatomic, assign) NSInteger bmIndex;

/** The ImagePreprocessingMode used when generating the current Intermediate result */
@property (nonatomic, assign) EnumImagePreprocessingMode imagePreprocessingMode;

/** The array index of current used ImagePreprocessingMode in ImagePreprocessingModes setting */
@property (nonatomic, assign) NSInteger ipmIndex;

/** The id of the ROI generated by the SDK */
@property (nonatomic, assign) NSInteger roiId;

/** The RegionPredetectionMode used when generating the current Intermediate result */
@property (nonatomic, assign) EnumRegionPredetectionMode regionPredetectionMode;

/** The array index of current used RegionPredetectionMode in RegionPredetectionModes setting */
@property (nonatomic, assign) NSInteger rpmIndex;

/** The GrayscaleTransformationMode used when generating the current Intermediate result */
@property (nonatomic, assign) EnumGrayscaleTransformationMode grayscaleTransformationMode;

/** The array index of current used GrayscaleTransformationMode in GrayscaleTransformationModes setting */
@property (nonatomic, assign) NSInteger gtmIndex;

/** The ColourConversionMode used when generating the current Intermediate result */
@property (nonatomic, assign) EnumColourConversionMode colourConversionMode;

/** The array index of current used ColourConversionMode in ColourConversionModes setting */
@property (nonatomic, assign) NSInteger cicmIndex;

/** The ColourClusteringMode used when generating the current Intermediate result */
@property (nonatomic, assign) EnumColourClusteringMode colourClusteringMode;

/** The array index of current used ColourClusteringMode in ColourClusteringModes setting */
@property (nonatomic, assign) NSInteger ccmIndex;

/** The scal down ratio */
@property (nonatomic, assign) NSInteger scaleDownRatio;

/** The id of the operated frame */
@property (nonatomic, assign) NSInteger frameId;

@end


/**
* Stores the contour
*
*/
@interface iContour : NSObject

/** The total points count of the contour */
@property (nonatomic, assign) NSInteger pointsCount;

/** The points array */
@property (nonatomic, nonnull) NSArray* points;

@end


/**
* Stores the image data.
*
*/
@interface iImageData : NSObject

/** The image data content in a byte array */
@property (nonatomic, nonnull) NSData* bytes;

/** The width of the image in pixels */
@property (nonatomic, assign) NSInteger width;

/** The height of the image in pixels */
@property (nonatomic, assign) NSInteger height;

/** The stride of the image (also called scan width) */
@property (nonatomic, assign) NSInteger stride;

/** The image pixel format used in the image byte array */
@property (nonatomic, assign) EnumImagePixelFormat format;

@end


/**
* Stores the line segment.
*
*/
@interface iLineSegment : NSObject

@property (nonatomic, assign) CGPoint startPoint;
/** The start point of the line segment */

@property (nonatomic, assign) CGPoint endPoint;
/** The end point of the line segment */

@end


/**
* Stores the region of interest
*
*/
@interface iRegionOfInterest : NSObject

/**The id generated by the SDK */
@property (nonatomic, assign) NSInteger roiId;

/**The left top point of the region */
@property (nonatomic, assign) CGPoint point;

/**The width of the region */
@property (nonatomic, assign) NSInteger width;

/**The height of the region */
@property (nonatomic, assign) NSInteger height;

@end


/**
 * Protocol for a delegate to handle callback when text result return.
 */
@protocol DBRTextResultDelegate <NSObject>

@required
/**
* Represents the method that will handle the text result array returned by the SDK.
*
* @param frameId The id of the frame.
* @param pResults Recognized barcode results of the frame..
* @param pUser Arguments pass to your function.
*
* @sa TextResultArray
*/
- (void)textResultCallback:(NSInteger)frameId results:(NSArray<iTextResult*>*)results userData: (NSObject*)userData;

@end

/**
 * Protocol for a delegate to handle callback when intermediate result return.
 */
@protocol DBRIntermediateResultDelegate <NSObject>

@required
/**
* Represents the method that will handle the intermediate result array returned by the SDK.
*
* @param frameId The id of the frame.
* @param pResults The intermediate results of the frame.
* @param pUser Arguments pass to your function.
*
* @sa IntermediateResultArray
*/
- (void)intermediateResultCallback:(NSInteger)frameId results:(NSArray<iIntermediateResult*>*)results userData: (NSObject*)userData;

@end

/**
 * Protocol for a delegate to handle callback when error return.
 */
@protocol DBRErrorDelegate <NSObject>

@required
/**
 * Represents the method that will handle the error code returned by the SDK.
 *
 * @param frameId The id of the frame.
 * @param errorCode Error Code generated when decoding the frame.
 * @param pUser Arguments pass to your function.
 *
 * @sa ErrorCode
 */
- (void)errorCallback:(NSInteger)frameId errorCode:(NSInteger)errorCode userData: (NSObject*)userData;

@end

/**
 * Protocol for a delegate to handle callback when license server return.
 */
@protocol DBRServerLicenseVerificationDelegate <NSObject>

@required
/**
  * The callback of license server.
  *
  * @param [in,out] isSuccess The value of whether the license verification was successful.
  * @param [in,out] error The error message from license server.
  */
- (void)licenseVerificationCallback:(bool)isSuccess error:(NSError * _Nullable)error;


@end


/**
* Defines a class that provides functions for working with extracting barcode data. 
* 
* Four methods are now supported for editing runtime settings - reset, initialize, append, update.
* - Reset runtime settings: reset all parameters in runtime setting to default value.
* 
* - Initialize with template: reset runtime settings firstly and replace all parameters in runtime setting with the values specified in given template regardless of the current runtime settings.
* 
* - Append template to runtime settings: append template and update runtime settings; the conflicting values will be assigned by the rules shown in DBRPublicRuntimeSettings.
* 
* - Update with struct: update current runtime settings by the values specified in given struct directly; the parameter not be defined in struct will remain its original value.
* 
* 
* @par References
* More information about public parameters and template file can be found in file DBR_Developer's_Guide.pdf.
* 
* 
* @sa DBRPublicRuntimeSettings
*/

@interface DynamsoftBarcodeReader: NSObject

 /**
  * Stores the license used in DynamsoftBarcodeReader.
  */
@property (nonatomic, nonnull) NSString* license;

/**
 * @name Initiation Funcitons
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
- (instancetype _Nonnull)initWithLicense:(NSString* _Nonnull)license;

/**
 * Initializes barcode reader license and connects to the specified server for online verification.
 * 
 * @param [in] licenseSeServer The name/IP of the license server.		   
 * @param [in] licenseKey The license key of Barcode Reader.
 * @param [in,out] connectionDelegate The delegate to handle callback when license server return.
 *
 * @return The instance of DynamsoftBarcodeReader.
 */

- (instancetype _Nonnull)initWithLicenseFromServer:(NSString* _Nullable)licenseSeServer licenseKey:(NSString* _Nonnull)licenseKey verificationDelegate:(id)connectionDelegate;


/**
 * Outputs the license content as an encrypted string from the license server to be used for offline license verification.
 *
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 * @return The output string which stores the contents of license.
 *
 */	
- (NSString *_Nullable)outputLicenseToString:(NSError* _Nullable * _Nullable)error;

/**
 * @}
 * @name Basic Setting Funcitons
 * @{
 */

/**
 * Gets current settings and save it into a struct.
 *
 * @return A DBRPublicRuntimeSettings storing current runtime settings.
 *
 */
- (iPublicRuntimeSettings* _Nullable)getRuntimeSettings:(NSError* _Nullable * _Nullable)error;

/**
 * Update runtime settings with a given struct.
 *
 * @param [in] settings The struct of template settings.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 */
- (void)updateRuntimeSettings:(iPublicRuntimeSettings* _Nonnull)settings
                        error:(NSError* _Nullable * _Nullable)error;
/**
 * Resets all parameters to default values.
 *
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 */
- (void)resetRuntimeSettings:(NSError* _Nullable * _Nullable)error;

/**
	 * Sets the optional argument for a specified mode in Modes parameters.
	 * 
	 * @param [in] modeName The mode parameter name to set argument.
	 * @param [in] index The array index of mode parameter to indicate a specific mode.
	 * @param [in] argumentName The name of the argument to set.
	 * @param [in] argumentValue The value of the argument to set.
 	 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.			  
	 *
	 * @par Remarks:
	 *		Check @ref ModesArgument for details
	 *
	 */
-(void)SetModeArgument:(NSString* _Nonnull)modeName
                     index:(NSInteger)index 
                     argumentName:(NSString* _Nonnull)argumentName
                     argumentValue:(NSString* _Nonnull)argumentValue
                     error:(NSError* _Nullable * _Nullable)error;

/**
 * @}
 * @name Decoding Funcitons
 * @{
 */

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
- (NSArray<iTextResult*>* _Nullable)decodeBase64:(NSString* _Nonnull)base64
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
- (NSArray<iTextResult*>* _Nullable)decodeImage:(UIImage* _Nonnull)image
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
- (NSArray<iTextResult*>* _Nullable)decodeBuffer:(NSData* _Nonnull)buffer
                                      withWidth:(NSInteger)width
                                         height:(NSInteger)height
                                         stride:(NSInteger)stride
                                         format:(EnumImagePixelFormat)format
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
- (NSArray<iTextResult*>* _Nullable)decodeFileWithName:(NSString* _Nonnull)name
                                         templateName:(NSString* _Nonnull)templateName
                                                error:(NSError* _Nullable * _Nullable)error;

/**
 * Starts a new thread to decode barcodes from the inner frame queue.
 * 
 * @param [in] maxQueueLength The max count of frames waiting for decoding.
 * @param [in] maxResultQueueLength The max count of frames whose results (text result/localization result) will be kept for further reference.
 * @param [in] width The width of the frame image in pixels.
 * @param [in] height The height of the frame image in pixels.
 * @param [in] stride The stride of the frame image (also called scan width).
 * @param [in] format The image pixel format used in the image byte array.
 * @param [in] templateName (Optional) The template name.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 */
-(void)startFrameDecoding:(NSInteger)maxQueueLength
                     maxResultQueueLength:(NSInteger)maxResultQueueLength
                     width:(NSInteger)width
                     height:(NSInteger)height
                     stride:(NSInteger)stride
                     format:(EnumImagePixelFormat)format
                     templateName:(NSString* _Nonnull)templateName
                     error:(NSError* _Nullable * _Nullable)error;


/**
 * Append a frame image buffer to the inner frame queue.
 * 
 * @param [in] bufferBytes The array of bytes which contain the image data.
 *				   
 * @return Returns the Id of the appended frame
 *
 */	
-(NSInteger)appendFrame:(NSData*) bufferBytes;
 
 /**
 * Get current length of the inner frame queue.
 *				   
 * @return Returns the length of the inner frame queue.
 *
 */	
-(NSInteger)GetLengthOfFrameQueue;

/**
 * Stops the frame decoding thread created by StartFrameDecoding.
 * 
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 */
-(void)StopFrameDecoding:(NSError* _Nullable * _Nullable)error;

/**
 * @}
 * @name Advanced Setting Functions
 * @{
 */

/**
 * Gets the parameter templates name array.
 *
 * @return The template name array.
 *
 */
- (NSArray<NSString*>* _Nullable)allParameterTemplateNames: (NSError *__autoreleasing  _Nullable *)error;

/**
 * Initialize runtime settings with the settings in given JSON file.
 *
 * @param [in] fileName The path of the settings file.
 * @param [in] conflictMode The parameter setting mode, which decides to inherit parameters from
 * 			  previous template setting or overwrite previous settings and replace by new template.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 * 
 * @sa DynamsoftBarcodeReader DBRPublicRuntimeSettings
 */
- (void)initRuntimeSettingsWithFile:(NSString* _Nonnull)fileName
                       conflictMode:(EnumConflictMode)conflictMode
	                          error:(NSError* _Nullable * _Nullable)error;

/**
 * Initialize runtime settings with the settings in given JSON string.
 *
 * @param [in] content A JSON string that represents the content of the settings.
 * @param [in] conflictMode The parameter setting mode, which decides to inherit parameters from
 * 			  previous template setting or overwrite previous settings and replace by new template.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @sa DynamsoftBarcodeReader DBRPublicRuntimeSettings
 */
- (void)initRuntimeSettingsWithString:(NSString* _Nonnull)content
						  conflictMode:(EnumConflictMode)conflictMode
								 error:(NSError* _Nullable * _Nullable)error;

/**
 * Append a new template file to current runtime settings.
 *
 * @param [in] fileName The path of the settings file.
 * @param [in] conflictMode The parameter setting mode, which decides to inherit parameters from
 * 			  previous template setting or overwrite previous settings and replace by new template.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @sa DynamsoftBarcodeReader DBRPublicRuntimeSettings
 */
- (void)appendTplFileToRuntimeSettings:(NSString * _Nonnull)fileName
					      conflictMode:(EnumConflictMode)conflictMode
								 error:(NSError * _Nullable *_Nullable)error;

/**
 * Append a new template string to current runtime settings.
 *
 * @param [in] content A JSON string that represents the content of the settings.
 * @param [in] conflictMode The parameter setting mode, which decides to inherit parameters from
 * 			  previous template setting or overwrite previous settings and replace by new template.
 * @param [in,out] error Input a pointer to an error object. If an error occurs, this pointer is set to an actual error object containing the error information. You may specify nil for this parameter if you do not want the error information.
 *
 * @sa DynamsoftBarcodeReader DBRPublicRuntimeSettings
 */
- (void)appendTplStringToRuntimeSettings:(NSString * _Nonnull)content
							conflictMode:(EnumConflictMode)conflictMode
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
 * @name Callback Functions
 * @{
 */


/**
 * Sets call back function to process errors generated during frame decoding.
 * 
 * @param [in] errorDelegate Call back function.
 * @param [in] userData Customized arguments passed to your function.				 
 *
 */
-(void)setDBRErrorDelegate:(id)errorDelegate userData:(NSObject*)userData;

/**
 * Sets call back function to process text results generated during frame decoding.
 * 
 * @param [in] textResultDelegate Call back function.
 * @param [in] userData Customized arguments passed to your function.
 *				   
 */
-(void)setDBRTextResultDelegate:(id)textResultDelegate userData:(NSObject*)userData;

/**
 * Sets call back function to process intermediate results generated during frame decoding.
 * 
 * @param [in] intermediateResultDelegate Call back function.
 * @param [in] userData Customized arguments passed to your function.
 *
 */
-(void)setDBRIntermediateResultDelegate:(id)intermediateResultDelegate userData:(NSObject*)userData;

/**
 * @}
 * @name Results Functions
 * @{
 */

/**
 * Returns intermediate results containing the original image, the colour clustered image, the binarized Image, contours, Lines, TextBlocks, etc.
 * 
 * @return Returns  intermediate result array.
 */
-(NSArray<iIntermediateResult*>* _Nullable)getIntermediateResult:(NSError* _Nullable * _Nullable)error;

/**
* @}
*/
@end


/**
 * @}
 * @}
 */
