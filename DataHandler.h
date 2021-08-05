#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iostream>



using namespace std;

using Key = int;
using Value = string;

class DataHandler {
public:
    virtual void HandleDatum(const Key& key, const Value& value) = 0;
    virtual ~DataHandler() {};
};

class DataProvider {
public:
    virtual const Value& GetDatum(const Key& key) = 0;
    virtual const vector<Value>& GetData(const std::vector<Key>& keys) = 0;
    virtual ~DataProvider() {};
};

struct DataVisualizer {
    DataVisualizer(DataHandler& handler, DataProvider& provider) :
        m_handler(handler),
        m_provider(provider)
    {
        //primitive test
        generateData();
        visualize();
    }

    void generateData() {
        m_handler.HandleDatum(0, "zero");
        m_handler.HandleDatum(1, "one");
        m_handler.HandleDatum(2, "two");
    }
    void visualize() {
        cout << m_provider.GetDatum(1)<<endl;
        cout << "Single data checked\n";

        vector<Key> keys;

        int myarray[] = { 0,1,2 };
        keys.insert(keys.begin(), myarray, myarray + 3);

        const vector<Value>& value = m_provider.GetData(keys);

        for (auto it = value.begin(); it != value.end(); ++it)
        {
            cout << *it << "\t";
        }
    }

    DataHandler& m_handler;
    DataProvider& m_provider;
};




template <class DataStorage>
// Not sure that multy-inheritation is good idea.
class DataManager : public DataHandler, public DataProvider {
    // implementation goes here	

private:
    //First we need some container for values. We use templates in order to be able to use Sequence and Associative containers.
    DataStorage DataContainer;
    //Also we need some storage, which will return multiple values.
    vector<Value> DataOutput;

public:
   


    DataManager() {};

    //Implement destructor to prevent memory leak.
    ~DataManager()
    {
        DataContainer.clear();
        DataOutput.clear();
    }

    //Also there should be some = and copy constructor 
    
    //Save input data. Need implementation for every type of container.
    void InputData(const Key& key, const Value& value);
    //Return value with index [key]. Need implementation for every type of container.
    const Value& OutputSingleValue(const Key& key);


    // Implement interface functions.
    virtual const Value& GetDatum(const Key& key) {
        return OutputSingleValue(key);
    };

    virtual const vector<Value>& GetData(const vector<Key>& keys) {           
        
        //Suppose there could be more elegant sollution, but dont have any better ideas.
        DataOutput.clear();
        for (auto it = keys.begin(); it != keys.end(); ++it)
        {
            DataOutput.push_back(OutputSingleValue(*it));
        }
        return DataOutput;
    };

    virtual void HandleDatum(const Key& key, const Value& value) {
        InputData(key, value);
    };



};
