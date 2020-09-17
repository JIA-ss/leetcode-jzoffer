#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main() {
    //istringstream 分割字符串，使用getline(iss,str,split);
    cout << "istringstream 分割字符串" << endl;
    string a = "a,b,c,d,e,f,g";
    string b = "h\ni\nj\nk\nl\nm\nn";
    istringstream iss;
    iss.clear();
    iss.str(a);
    string p;
    while(getline(iss,p,',')) {
        cout << p << endl;
    }
    iss.clear();
    iss.str(b);
    while (getline(iss,p,'\n')) {
        cout << p << endl;
    }

    //istringstream 使用方法
    cout << "istringstream 使用方法" << endl;
    istringstream istr;
    istr.str("1 56.7");
    //上述两个过程可以简单写成 istringstream istr("1 56.7");
    cout << istr.str() << endl;
    int a_;
    float b_;
    istr >> a_;
    cout << a_ << endl;
    istr >> b_ ;
    cout << b_ << endl;


    //ostringstream 使用方法
    cout << "ostringstream 使用方法"<<endl;
    ostringstream ostr;
    ostr.str("abc");
    cout << ostr.str() << endl;
    //如果构造的时候设置了字符串参数,那么增长操作的时候不会从结尾开始增加,而是修改原有数据,超出的部分增长
    ostr.put('d');
    cout << ostr.str() << endl;
    ostr.put('e');
    cout << ostr.str() << endl;
    ostr<<"fg";

    string gstr = ostr.str();
    cout<<gstr << endl;


    //stringstream 使用方法
    cout << "stringstream 使用方法" << endl;
    stringstream sstr("c");
    cout << sstr.str() << endl;
    sstr.put('d');
    cout << sstr.str() << endl;
    sstr.put('e');
    cout << sstr.str() << endl;
    sstr<<"fg";
    string gsstr = sstr.str();
    cout<<gsstr<<endl;

    char a__;
    sstr>>a__; //可以看到stringstream对象既可以做输入流也可以做输出流
    cout<<a__ << endl;

    return 0;
}
