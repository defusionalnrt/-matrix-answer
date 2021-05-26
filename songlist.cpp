
#include <string>
#include <iostream>
using namespace std;

class SongList {
    std::string owner;          // 歌单拥有者
    unsigned int size;         // 歌单中有效歌曲的数量
    unsigned int capacity;          // 歌单的最大容量
    std::string *songs;         // 歌曲列表，一个string数组

public:
    // 初始化的歌曲列表中会保证没有重复歌曲
    SongList(const std::string _owner, unsigned int _size, unsigned int _capacity, std::string *_songs);

    SongList(const SongList &songList);

    // 添加歌曲，请考虑去重的情况（如果歌曲已经存在则不添加）、歌单已经满了需要扩容的情况，扩容方案自选
    // 扩容方案1：原地扩容，C语言中有个realloc函数可以实现
    // 扩容方案2：重新开辟一个更大容量songs歌曲列表，并将当前的数据迁移过去
    void addSong(const std::string &song);

    // 删除指定歌曲，歌曲不存在则无动作
    void removeSong(const std::string &song);

    // 清空歌曲
    void clearSong();

    SongList &operator=(const SongList &songList);

    friend ostream &operator<<(ostream &os, const SongList &songList);

    ~SongList();
};
SongList::SongList(const std::string s, unsigned int _size, unsigned int _capacity, std::string *ss){
    owner=s;
    size=_size;
    capacity=_capacity;
    songs=new string[100];
    for(int i=0;i<size;i++){
        songs[i]=ss[i];
    }
}
void SongList::addSong(const std::string &song){
    for(int i=0;i<size;i++){
        if(song==songs[i]){
            return;
        }
    }
    if(size==capacity){
        capacity++;
    }
    songs[size]=song;
    size++;
}
ostream &operator<<(ostream &os, const SongList &songList){
    if(!songList.size){
        os<<songList.owner<<"'s SongList is Empty.";
    }
    else{
        os<<"owner:"<<songList.owner<<endl;
        os<<"songs:"<<endl;
        for(int i=0;i<songList.size;i++){
            os<<songList.songs[i]<<endl;
        }
    }
    return os;
}
void SongList::removeSong(const std::string &song){
    
    int q=0;
    for(int i=0;i<size;i++){
        q=i;
        if(songs[i]==song){
            break;
        }
    }
    for(int i=q;i<size-1;i++){
        songs[i]=songs[i+1];
    }
    size--;
}
SongList &SongList::operator=(const SongList &songList){
    owner=songList.owner;
    size=songList.size;
    capacity=songList.capacity;
    for(int i=0;i<size;i++){
        songs[i]=songList.songs[i];
    }
    return *this;
}
void SongList::clearSong(){
    size=0;

}
SongList::~SongList(){
    delete [] songs;
}
SongList::SongList(const SongList &songList){
    owner=songList.owner;
    size=songList.size;
    capacity=songList.capacity;
    songs=new string[100];
    for(int i=0;i<size;i++){
        songs[i]=songList.songs[i];
    }
}
int main() {
    int numSongs;
    cin >> numSongs;
    getchar();                  //读取换行符
    string name2 = "MakaBaka";
    string *songs = new string[numSongs];
    for (int i = 0; i < numSongs; ++i) {
        getline(cin, songs[i]);
    }
    string toAddAndRemoved = "Lights Frightened The Captain";

    SongList songList1(name2, numSongs, numSongs, songs);
    songList1.addSong(toAddAndRemoved);
    songList1.addSong(toAddAndRemoved);

    SongList songList2(songList1);
    songList2 = songList2;
    songList2.removeSong(toAddAndRemoved);

    SongList songList3 = songList2;
    songList3.clearSong();


    cout << songList1 << endl;
    cout << songList2 << endl;
    cout << songList3 << endl;
    return 0;
}