//
// Created by alex on 10/7/19.
//

#ifndef SHUALEETCODE_TESTENGINE_H
#define SHUALEETCODE_TESTENGINE_H

#endif //SHUALEETCODE_TESTENGINE_H
using namespace std;
enum RC {SUCCESS};

template <typename T> void print_element(T element){
    cout << element << "\t";
}

template <typename T> void print_vector(vector<T> &v){
    for_each(v.begin(), v.end(), print_element<T>);
}
class TestEngine{
public:
    static TestEngine &instance();
    RC test();
protected:
    TestEngine();
    ~TestEngine();
    TestEngine(const TestEngine &);
    TestEngine &operator=(const TestEngine &);
private:
    static TestEngine *_test_engine;
};