#include <iostream>
#include <filesystem>

using namespace std;

class MediaPlayer {
public:
	virtual void play(string file_type, string file_name) = 0;
	virtual ~MediaPlayer(){}
};

class AdvancedMediaPlayer {
public:
	AdvancedMediaPlayer() {}
	virtual void playVLC(string file_name) = 0;
	virtual void playMP4(string file_name) = 0;
	virtual void openExcelFile(string file_name) = 0;
	virtual void openTextFile(string file_name) = 0;

	virtual ~AdvancedMediaPlayer(){}
};

class VLCPlayer : public AdvancedMediaPlayer {
public:
	void playVLC(string file_name) {
		cout << "Playing VLC file. Name: " << file_name << "\n";
	}

	void playMP4(string file_name) {
	}

	void openTextFile(string file_name) {
	}

	void openExcelFile(string file_name) {
	}

	~VLCPlayer() {}
};

class MP4Player : public AdvancedMediaPlayer {
public:
	void playMP4(string file_name) {
		cout << "Playing MP4 file. Name: " << file_name << "\n";
	}

	void playVLC(string file_name) {
		// must implement because pure virtual base class
		// should never be called
	}

	void openTextFile(string file_name) {
	}

	void openExcelFile(string file_name) {
		// must implement because pure virtual base class
		// should never be called
	}

	~MP4Player() {}
};

class TextFileReader : public AdvancedMediaPlayer {
public:
	void playVLC(string file_name) {
	}

	void playMP4(string file_name) {
	}
	void openTextFile(string file_name) {
		cout << "Opening Text file. Name: " << file_name << "\n";
	}

	void openExcelFile(string file_name) {

	}

	~TextFileReader() {}
};

class ExcelFileReader : public AdvancedMediaPlayer {
public:
	void playVLC(string file_name) {
	}

	void playMP4(string file_name) {
		// must implement because pure virtual base class
		// should never be called
	}
	void openExcelFile(string file_name) {
		cout << "Opening Excel file. Name: " << file_name << "\n";
	}

	void openTextFile(string file_name) {
		// must implement because pure virtual base class
		// should never be called
	}

	~ExcelFileReader() {}
};

class MediaAdapter : public MediaPlayer {
	AdvancedMediaPlayer *advancedMusicPlayer;

public:
	MediaAdapter(string file_type) {
		if (file_type.compare("vlc") == 0) {
			advancedMusicPlayer = new VLCPlayer;
		} else if (file_type.compare("mp4") == 0) {
			advancedMusicPlayer = new MP4Player;
		}
		else if (file_type.compare("mp4") == 0) {
			advancedMusicPlayer = new ExcelFileReader;
		}
		else if (file_type.compare("mp4") == 0) {
			advancedMusicPlayer = new TextFileReader;
		}
	}

	void play(string file_type, string file_name) {
		if (file_type.compare("vlc") == 0) {
			advancedMusicPlayer->playVLC(file_name);
		} else if (file_type.compare("mp4") == 0) {
			advancedMusicPlayer->playMP4(file_name);
		}
	}

	~MediaAdapter() {
		delete advancedMusicPlayer;
	}
};

class AudioPlayer : public MediaPlayer {
	MediaAdapter *mediaAdapter;

public:
	void play(string file_type, string file_name) {
		// inbuilt support to play mp3 music files
		if (file_type.compare("mp3") == 0) {
			cout << "Playing MP3 file. Name: " << file_name << "\n";
		} else if (
			file_type.compare("vlc") == 0 || file_type.compare("mp4") == 0) {
			mediaAdapter = new MediaAdapter(file_type);
			mediaAdapter->play(file_type, file_name);
			delete mediaAdapter;
		}
		else if (file_type.compare("xlsx") == 0){
			cout << "Verifying Excel File integrity. Name: " << file_name << endl;
		}
		else {
			cout << "Invalid media. " << file_type;
			cout << " format not supported";
			cout << "\n";
		}
	}
};

int main() {
	AudioPlayer audioPlayer;

	audioPlayer.play("mp3", "beyond_the_horizon.mp3");
	audioPlayer.play("mp4", "alone.mp4");
	audioPlayer.play("vlc", "far_far_away.vlc");
	audioPlayer.play("avi", "mind_me.avi");

	audioPlayer.play("txt", "testing.txt");
	audioPlayer.play("xlsx", "lyricsdatabase.xlsx");

}