#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    // ---------- 1. INSERT ----------
    unordered_map<string, int> shop;
    shop["Apple"] = 50;
    shop["Banana"] = 20;
    shop["Mango"] = 80;
    shop["Apple"] = 60;  // UPDATE: overwrites old value

    cout << "--- SHOP LIST ---" << endl;
    for(auto& entry : shop)
        cout << entry.first << " : " << entry.second << endl;

    // ---------- 2. SEARCH (O(1)) ----------
    string key = "Mango";
    if(shop.find(key) != shop.end())
        cout << "\n" << key << " found, price = " << shop[key] << endl;
    else
        cout << "\n" << key << " not found" << endl;

    // ---------- 3. DELETE ----------
    shop.erase("Banana");
    cout << "\nAfter deleting Banana:" << endl;
    for(auto& entry : shop)
        cout << entry.first << " : " << entry.second << endl;

    // ---------- 4. FREQUENCY COUNT (classic pattern) ----------
    cout << "\n--- FREQUENCY COUNT ---" << endl;
    string sentence = "apple banana apple mango banana apple";
    unordered_map<string, int> freq;
    string word = "";

    for(char c : sentence){
        if(c == ' '){
            freq[word]++;
            word = "";
        } else {
            word += c;
        }
    }
    freq[word]++;  // last word

    for(auto& entry : freq)
        cout << entry.first << " : " << entry.second << " times" << endl;

    // ---------- 5. COUNT (size) ----------
    cout << "\nTotal unique fruits in shop: " << shop.size() << endl;

    return 0;
}