package ex1;


import java.util.ArrayList;

public class Music{
	
	private String title;
	private ArrayList<String> participants;

	Music(String title){
		participants = new ArrayList<String>();
		this.title = title;
	}

	public String getTitle(){
		return title;
	}
	public void setTitle(String title){
		this.title = title;
	}
	public void addParticipant(String p){
		participants.add(p);
	}
	public void printAllParticipants(){
		System.out.printf("The participant(s) of '%s' is(are):\n", this.title);
		for(int i=0; i<participants.size(); i++){
			System.out.printf("%s\n", participants.get(i));
		}
	}

}