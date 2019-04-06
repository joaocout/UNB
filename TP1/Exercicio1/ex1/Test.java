package ex1;


import java.util.ArrayList;

public class Test{

    public static void searchArtistByNationality(String a, ArrayList<Artist> list){
        int counter=0;
        System.out.printf("Searching for: %s\n", a);
        for(int i=0; i<list.size(); i++){
            if(a.equalsIgnoreCase(list.get(i).getNationality())){
                System.out.printf("%s\n", list.get(i).getName());
                counter++;
            }
       }
       System.out.printf("%d result(s) found.\n", counter);
    }

    public static void searchArtistByName(String a, ArrayList<Artist> list){
        int counter=0;
        System.out.printf("Searching for: %s\n", a);
        for(int i=0; i<list.size(); i++){
            if(list.get(i).getName().toLowerCase().contains(a.toLowerCase())){
                System.out.printf("%s\n", list.get(i).getName());
                counter++;
            }
       }
       System.out.printf("%d result(s) found.\n", counter);
    }

    public static void main(String[] args){

        ArrayList<Artist> list = new ArrayList<Artist>();

        Artist uni = new Artist("Steven Universo", "USA");
        Artist steven = new Artist("Steven Wilson", "England");
        Artist opeth = new Artist("Opeth", "Sweden");
        Artist kings = new Artist("Kings of Leon", "USA");
        Artist bungle = new Artist("Mr. Bungle", "USA");

        list.add(uni);
        list.add(steven);
        list.add(opeth);
        list.add(kings);
        list.add(bungle);


        Album blackwater = new Album("Blackwater Park", 67, 2001);
        
        Music affinity = new Music("The Lepper Affinity");
        blackwater.addMusic(affinity); 
        opeth.addMusic(affinity);

        Music bleak = new Music("Bleak");
        blackwater.addMusic(bleak); 
        opeth.addMusic(bleak); steven.addMusic(bleak);

        Music harvest = new Music("Harvest");
        blackwater.addMusic(harvest);
        opeth.addMusic(harvest); steven.addMusic(harvest);

        Music drapery = new Music("The Drapery Falls");
        blackwater.addMusic(drapery);
        opeth.addMusic(drapery); steven.addMusic(drapery);

        Music november = new Music("Dirge for November");
        blackwater.addMusic(november);
        opeth.addMusic(november);

        Music potrait = new Music("The Funeral Potrait");
        blackwater.addMusic(potrait);
        opeth.addMusic(potrait); steven.addMusic(potrait);

        Music ivy = new Music("Patterns in the Ivy");
        blackwater.addMusic(ivy);
        opeth.addMusic(ivy);

        Music park = new Music("Blackwater Park");
        blackwater.addMusic(park);
        opeth.addMusic(park);

        opeth.addAlbum(blackwater);
        
        
        Album damnation = new Album("Damnation", 43, 2003);

        Music windowpane = new Music("Windowpane");
        damnation.addMusic(windowpane);
        opeth.addMusic(windowpane);

        Music time = new Music("In My Time of Need");
        damnation.addMusic(time);
        opeth.addMusic(time);

        Music death = new Music("Death Whispered a Lullaby");
        damnation.addMusic(death);
        opeth.addMusic(death); steven.addMusic(death);

        Music closure = new Music("Closure");
        damnation.addMusic(closure);
        opeth.addMusic(closure);

        Music hope = new Music("Hope Leaves");
        damnation.addMusic(hope);
        opeth.addMusic(hope);

        Music rid = new Music("To Rid the Disease");
        damnation.addMusic(rid);
        opeth.addMusic(rid);

        Music ending = new Music("Ending Credits");
        damnation.addMusic(ending);
        opeth.addMusic(ending);

        Music weakness = new Music("Weakness");
        damnation.addMusic(weakness);
        opeth.addMusic(weakness);

        opeth.addAlbum(damnation);


        drapery.printAllParticipants();
        System.out.println(" ");
        System.out.println(" ");

        opeth.printAllAlbumsSortbyTitle();
        System.out.println(" ");
        System.out.println(" ");
        
        opeth.printAllAlbumsSortbyYear();
        System.out.println(" ");
        System.out.println(" ");

        opeth.printAllAlbumsSortbyLength();
        System.out.println(" ");
        System.out.println(" ");

        opeth.printAllMusics();
        System.out.println(" ");
        System.out.println(" ");

        steven.printAllMusics();
        System.out.println(" ");
        System.out.println(" ");

        searchArtistByNationality("USA", list);
        System.out.println(" ");
        System.out.println(" ");

        searchArtistByNationality("sweden", list);
        System.out.println(" ");
        System.out.println(" ");

        searchArtistByName("steven", list);
    }

}
