package ex1;


import java.util.ArrayList;

public class Album{

	private String title;
	private int length, year;
	private ArrayList<Music> musics;

	Album(String title, int length, int year){
		musics = new ArrayList<Music>();
		this.title = title;
		this.length = length;
		this.year = year;
	}

	public String getTitle(){
		return title;
	}
	public void setTitle(String title){
		this.title = title;
	}
	public int getLength(){
		return length;
	}
	public void setLength(int length){
		this.length = length;
	}
	public int getYear(){
		return year;
	}
	public void setYear(int year){
		this.year = year;
	}
	public void addMusic(Music m){
		musics.add(m);
	}
	public void printAllMusics(){
		System.out.printf("All songs in '%s':\n", this.title);
		for(int i=0; i<musics.size(); i++){
			System.out.printf("%d - %s\n", i+1, musics.get(i).getTitle());
		}
	}
	public int getAlbumSize(){
		return musics.size();
	}

}