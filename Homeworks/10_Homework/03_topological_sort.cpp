#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

void topologicalSort(
        unordered_set<char> &visitedNodes,
        unordered_map<char, vector<char>> &graph,
        list<char> &orderedLetters,
        char node) {
    if (visitedNodes.count(node) > 0) {
        return;
    }

    visitedNodes.insert(node);
    for (auto child : graph[node]) {
        topologicalSort(visitedNodes, graph, orderedLetters, child);
    }

    orderedLetters.push_front(node);
}

list<char> topologicalSort(unordered_map<char, vector<char>> &graph) {
    unordered_set<char> visitedNodes;
    list<char> orderedLetters;

    vector<char> letters;
    for (const auto &node : graph) {
        letters.push_back(node.first);
    }

    sort(letters.begin(), letters.end());

    for (auto letter : letters) {
        topologicalSort(visitedNodes, graph, orderedLetters, letter);
    }

    return orderedLetters;
}

void addEdge(int parent, int child, unordered_map<char, vector<char>> &graph) {
    if (graph.count(parent) == 0) {
        graph[parent] = vector<char>();
    }

    graph[parent].push_back(child);
}

void buildGraph(unordered_map<char, vector<char>> &graph, vector<string> &words) {
    if (words.empty()) {
        return;
    }

    string previousWord = words[0];
    graph[previousWord[0]] = vector<char>();

    for (int i = 1; i < words.size(); ++i) {
        string currentWord = words[i];

        for (int j = 0; j < min(currentWord.length(), previousWord.length()); ++j) {
            if (currentWord[j] != previousWord[j]) {
                addEdge(previousWord[j], currentWord[j], graph);
                break;
            }
        }

        previousWord = currentWord;
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    unordered_map<char, vector<char>> graph;
    buildGraph(graph, words);

    list<char> orderedLetters = topologicalSort(graph);
    vector<char> nodes;
    for (auto letter : orderedLetters) {
        cout << letter << " ";
    }
}
