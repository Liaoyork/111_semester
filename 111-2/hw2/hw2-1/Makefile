All:Spotify
Spotify:Spotify.o User.o Song.o Playlist.o main.o
	g++ Spotify.o User.o Playlist.o Song.o main.o -o Spotify
Spotify.o:Spotify.cpp
	g++ -c Spotify.cpp
User.o:User.cpp
	g++ -c User.cpp
Playlist.o:Playlist.cpp
	g++ -c Playlist.cpp
Song.o:Song.cpp
	g++ -c Song.cpp
main.o:main.cpp
	g++ -c main.cpp
clean:
	rm *.o
run:
	./Spotify music.txt
