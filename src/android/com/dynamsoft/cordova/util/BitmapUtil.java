package com.dynamsoft.cordova.util;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;
import android.util.Base64;

import java.io.InputStream;

public class BitmapUtil {

    public static Drawable base64ToDrawable(String base64Data) {
        return bitmapToDrawable(base64ToBitmap(base64Data));
    }

    public static Bitmap base64ToBitmap(String base64Data) {
        if (base64Data == null) {
            return null;
        }
        byte[] bytes = Base64.decode(base64Data, Base64.DEFAULT);
        if (bytes != null) {
            BitmapFactory.Options options = new BitmapFactory.Options();
            options.inJustDecodeBounds = true;
            BitmapFactory.decodeByteArray(bytes, 0, bytes.length, options);
            if (options.outWidth * options.outHeight > 2000 * 2000) {
                options.inTargetDensity = options.outWidth * options.outHeight;
                options.inDensity = 2000 * 2000;
            }
            options.inJustDecodeBounds = false;
            return BitmapFactory.decodeByteArray(bytes, 0, bytes.length, options);
        } else {
            return null;
        }
    }

    public static Drawable InputStreamToDrawable(InputStream is) {
        Bitmap bitmap = InputStreamToBitmap(is);
        return bitmapToDrawable(bitmap);
    }

    public static Bitmap InputStreamToBitmap(InputStream is) {
        return BitmapFactory.decodeStream(is);
    }

    public static Drawable bitmapToDrawable(Bitmap bitmap) {
        if (bitmap != null) {
            BitmapDrawable bd = new BitmapDrawable(Resources.getSystem(), bitmap);
            Drawable img = bd;
            return img;
        } else {
            return null;
        }
    }
}
