

#include "DataHandler.h"

/*
* Here we implement methods for all container we want to use. For example will be emplemented vector and map.
* For Seq-classes we can use insert() and at() methods for in/output.
* For Associate-classes we can use emplace() and find().

*/

void DataManager<map <Key, Value>>::InputData(const Key& key, const Value& value)
{
    /*
    * There should be some check if we try to use one key for different values.
    * However, in general its not problem for map, so I left it like that
    */
    DataContainer.emplace(key, value);
}

const Value& DataManager<map <Key, Value>>::OutputSingleValue(const Key& key)
{
    /*
    * There should be some check, if value with key is not exist.
    * However, its not error for map. It will return end(), so I left it like that.
    */
    return DataContainer.find(key)->second;
}


/*
* For Seq-classes, however, we have to handle situation, when key>lentgh(),  key<0. 
* 
*/
void DataManager<vector <Value>>::InputData(const Key& key, const Value& value)
{

    // Better throw here exception, but dont have enough time.
    if (key < 0){
        cout << "Warning, key<0, value wasn't recorded";
        return;
    }

    if (key > DataContainer.size()){
        DataContainer.resize(key);
    }
    DataContainer.insert(DataContainer.begin() + key, value);
}



const Value& DataManager<vector <Value>>::OutputSingleValue(const Key& key)
{
    // Better throw here exception, but dont have enough time.
    if (key < 0) {
        cout << "Warning, key<0, invalid key\n";
        return 0;
    }

    if (key > DataContainer.size()) {
        cout << "Warning, key>size(), invalid key\n";
        return 0;
    }
    return DataContainer.at(key);
}
