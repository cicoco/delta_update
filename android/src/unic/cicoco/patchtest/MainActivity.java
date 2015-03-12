package unic.cicoco.patchtest;

import java.io.IOException;

import unic.cicoco.patch.PatchClient;
import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;

public class MainActivity extends Activity {

	static {
		PatchClient.loadLibrary();
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		findViewById(R.id.mytest).setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				String path = Environment.getExternalStorageDirectory()
						.getPath() + "/test/";

				try {
					PatchClient.applyPatch(path + "old.apk", path + "new.apk",
							path + "my.patch");
					Log.d("juno", "success!");
				} catch (IOException e) {
					e.printStackTrace();
					Log.d("juno", "e:" + e.getMessage());

				}
			}
		});
	}
}
