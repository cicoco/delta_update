package unic.cicoco.patch;

import java.io.IOException;

/**
 * Created by tafia on 15-3-9.
 */
public class PatchClient {

	private static native int applyPatch2APK(String oldapk_filepath,
			String newapk_savepath, String patchpath);

	/**
	 * @param oldAPKPath
	 *            旧版apk文件的路径
	 * @param newAPKPath
	 *            新版apk文件的路径(完整路径)
	 * @param patchPath
	 *            增量包的路径
	 * @throws java.io.IOException
	 */
	public static void applyPatch(String oldAPKPath, String newAPKPath,
			String patchPath) throws IOException {
		applyPatch2APK(oldAPKPath, newAPKPath, patchPath);
	}

	public static void loadLibrary() {
		System.loadLibrary("unicpatch");
	}

}
