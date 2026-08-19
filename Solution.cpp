#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int c{},n{};
    cout << "Enter port capacity: ";
    cin >> c ;
    cout << "Enter number of containers: ";
    cin >> n ;
    int total_weight{};
    int max_weight{}, min_weight{};
    vector<int> weights = {};

    for (int i = 0; i < n; ++i){
        int weight{};
        cout << "Enter weight of container " << i + 1 << ": ";
        cin >> weight;
        weights.push_back(weight);
        if (i == 0){
            max_weight = weight;
            min_weight = weight;
        } else {
            if (weight > max_weight){
                max_weight = weight;
            }
            if (weight < min_weight){
                min_weight = weight;
            }
        }
        total_weight += weight;
    }

    string classification{},status{};
    if (total_weight > 200){
        classification = "Heavy";
    } else {
        classification = "Light";
    }

    if (total_weight < c){
        status = "Shipment can be unloaded";
    } else {
        status = "Shipment exceeds port capacity";
    }

    cout << "Total Shipment Weight: " << total_weight << endl;
    cout << "Average container weight: " << (total_weight) / n << endl;
    cout << "Heaviest container: " << max_weight << endl;
    cout << "Lightest container: " << min_weight << endl;
    cout << "Classification: " << classification << endl;
    cout << "Port capacity: " << c << endl;
    cout << "Status: " << status << endl;

    return 0;
}