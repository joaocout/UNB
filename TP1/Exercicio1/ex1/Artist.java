package ex1;


import java.util.ArrayList;
import java.util.Comparator;

public class Artist{
	
	private String name, nationality;
	private ArrayList<Album> albums;
	private ArrayList<Music> musics;

	Artist(String name, String nationality){
		this.name = name;
		this.nationality = nationality;
		albums = new ArrayList<Album>();
		musics = new ArrayList<Music>();
	}

	public String getName(){
		return name;
	}
	public void setName(String name){
		this.name = name;
	}
	public String getNationality(){
		return nationality;
	}
	public void setNationality(String nationality){
		this.nationality = nationality;
	}
	public void addAlbum(Album a){
		albums.add(a);
	}
	public void printAllAlbumsSortbyTitle(){
		albums.sort(Comparator.comparing(Album::getTitle));
		System.out.printf("Albums by %s sorted by title:\n", this.name);
		for(int i=0; i<albums.size(); i++){
			System.out.printf("%d - %s\n", i+1, albums.get(i).getTitle());
		}
	}
	public void printAllAlbumsSortbyYear(){
		albums.sort(Comparator.comparing(Album::getYear));
		System.out.printf("Albums by %s sorted by year:\n", this.name);
		for(int i=0; i<albums.size(); i++){
			System.out.printf("%d - %s - %d\n", i+1, albums.get(i).getTitle(), albums.get(i).getYear());
		}
	}
	public void printAllAlbumsSortbyLength(){
		albums.sort(Comparator.comparing(Album::getLength));
		System.out.printf("Albums by %s sorted by length:\n", this.name);
		for(int i=0; i<albums.size(); i++){
			System.out.printf("%d - %s - %d min\n", i+1, albums.get(i).getTitle(), albums.get(i).getLength());
		}
	}

	public void addMusic(Music m){
		musics.add(m);
		m.addParticipant(this.name);
	}
	public void printAllMusics(){
		System.out.printf("All songs by %s:\n", this.name);
		for(int i=0; i<musics.size(); i++){
			System.out.printf("%d - %s\n", i+1, musics.get(i).getTitle());
		}
	}
	
}