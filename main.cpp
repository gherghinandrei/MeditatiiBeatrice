#include<iostream>
using namespace std;

class Song {
private:
    char* songName;
    int time;
    char* artist;


public:

    //Constructor default
    Song(){
        this->songName = new char[strlen("Default name")+1];
        strcpy(this->songName,"Default name");
        this->time  = 0;
        this->artist = new char[strlen("Default artist name")+1];
        strcpy(this->artist,"Default artist name");
    }
    //Constructor cu parametrii
    Song(const char* songName, int time,const char* artist){
        this->songName = new char[strlen(songName)+1];
        strcpy(this->songName,songName);
        this->time  = time;
        this->artist = new char[strlen(artist)+1];
        strcpy(this->artist,artist);
    }

    Song(const Song &temp){
        this->songName = new char[strlen(temp.songName)+1];
        strcpy(this->songName,temp.songName);
        this->time  = temp.time;
        this->artist = new char[strlen(temp.artist)+1];
        strcpy(this->artist,temp.artist);
    }
    ~Song(){
        if(this->songName !=NULL)
        delete[]this->songName;
        
        if(this->artist!=NULL)
        delete[]this->artist;
    }
    void doSomething(){
        cout<<this->songName<<"  blablalbla"<<endl;
    }


    char* getSongName(){
        return this->songName;
    }

    void setSongName(char* songName){
        if(this->songName != NULL){
            delete[] this->songName;
        }
        this->songName = new char[strlen(songName)+1];
        strcpy(this->songName, songName);
    }


    
};




int main(){

    Song s1;
    cout<<s1.getSongName();
    

    Song s2("Smells like team spirit",3,"Nirvana");

    Song s3(s2);

    //cout<<s2.songName<<endl;
    s1.doSomething();

    s1.setSongName("sfhajfdsa");


    char* aux;
    aux = s1.getSongName();
    return 0;
}
