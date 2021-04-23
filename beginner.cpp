#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
template <typename T> T compare (T a,T b)
{
    return a<b?a:b;
}


template<class T>
class test{
private:
    T oneItem;
public:
    test(T a){oneItem=a;}
    T getoneItem() const{return oneItem;}
};
template<class T>
class Result{
    private:
        string name;
        vector<T> oneSlice;
    public:
        Result(){cout<<"hello Result"<<endl;}
        ~Result(){}
        void setResult(Result a){name = a.name;oneSlice = a.oneSlice;}
        void setResult(string a, vector<T> b){name = a; oneSlice = b;}
        string getname(){return name;}
        float getSlice(int i){return oneSlice[i];}
        virtual void print(){cout<<"haha buzzinga\n";}
        

};
class resultManager:public Result<float>{
    private:
        Result<float> result[5];    
    public:
        void initFromFile(const char* filename);
        bool compare(Result<float> a,Result<float> b);
        void swap(int i,int j);
        void setResult(int i,string a,vector<float>b){result[i].setResult(a,b);}
        void setResult(int i, Result<float> a){result[i].setResult(a);}
        void print()
        {
            for (int i=0;i<5;i++)
            {
                cout<<result[i].getname()<<" "<<result[i].getSlice(0)<<" "<<result[i].getSlice(1)<<" "<<result[i].getSlice(2)<<endl;
            }
        }
        Result<float> getResult(int i){return result[i];}
        float operator+(float b){return result[2].getSlice(2)+b;}
};
int main(int argc, const char * argv[]) {

    resultManager oneResultManager;
    oneResultManager.initFromFile(argv[1]);
    Result<float> *sample;
    sample = &oneResultManager;
    sample->print();
    oneResultManager.swap(1,2);
    
    cout<<compare(1,2)<<endl;
    test<float> test1(0.2);
    cout<<"template class test"<<test1.getoneItem()<<endl;
    cout<<"Redefine +:"<<oneResultManager+1<<endl;
    cout<<"swap result"<<endl;
    sample->print();
	return 0;
}
void resultManager::swap(int i,int j)
{
    Result a = getResult(i);
    Result b = getResult(j);
    setResult(j,a);
    setResult(i,b);
}
void resultManager::initFromFile(const char* filename){
    vector<vector<int>> user_arr;
    ifstream fp(filename); 
    string line;
    getline(fp,line);
    int k = 0;
    while (getline(fp,line)){ 
        vector<float> data_line;
        string number;
        istringstream readstr(line); 
        string name;
        for(int j = 0;j < 4;j++){ 
            getline(readstr,number,','); 
            if(j==0)
            {
                name = number;
                continue;
            }
            else{
                data_line.push_back( stof(number)); 
            }
        }
        
        setResult(k,name,data_line);
        k++;
    }
}
