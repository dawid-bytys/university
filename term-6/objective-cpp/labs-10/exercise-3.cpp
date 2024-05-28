#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Song {
 public:
  Song(const std::wstring& artist, const std::wstring& title)
      : artist(artist), title(title) {
    std::wcout << L"Song Constructor: " << artist << L" - " << title
               << std::endl;
  }

  ~Song() {
    std::wcout << L"Song Destructor: " << artist << L" - " << title
               << std::endl;
  }

  void play() const {
    std::wcout << L"Playing: " << artist << L" - " << title << std::endl;
  }

 private:
  std::wstring artist;
  std::wstring title;
};

template <typename... Args>
std::unique_ptr<Song> SongFactory(Args&&... args) {
  return std::make_unique<Song>(std::forward<Args>(args)...);
}

int main() {
  auto song = SongFactory(L"Michael Jackson", L"Beat It");

  std::vector<std::unique_ptr<Song>> songs;
  songs.push_back(SongFactory(L"Queen", L"Bohemian Rhapsody"));
  songs.push_back(SongFactory(L"AC/DC", L"Back In Black"));
  songs.push_back(SongFactory(L"Led Zeppelin", L"Stairway to Heaven"));

  for (const auto& song : songs) {
    song->play();
  }

  // for (const auto song : songs) {
  //     song->play();
  // }

  return 0;
}
