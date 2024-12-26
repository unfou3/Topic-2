#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Hàm ghi danh sách cạnh vào file
void WriteEdgeListToFile(int n, const vector<pair<int, int>>& edgeList, const string& fileName) {
    ofstream outFile(fileName);

    if (!outFile.is_open()) {
        cerr << "Không thể mở file " << fileName << endl;
        return;
    }

    // Ghi số đỉnh và số cạnh lên đầu file
    outFile << n << " " << edgeList.size() << endl;

    // Ghi danh sách cạnh
    for (const auto& edge : edgeList) {
        outFile << edge.first << " " << edge.second << endl;
    }

    outFile.close();
    cout << "Danh sách cạnh đã được ghi vào file: " << fileName << endl;
}

int main() {
    // Ma trận kề mẫu
    vector<vector<int>> adjacencyMatrix = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    vector<pair<int, int>> edgeList;
    int n = adjacencyMatrix.size(); // Số đỉnh

    // Chuyển đổi ma trận kề sang danh sách cạnh
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) { // Chỉ duyệt phần trên của ma trận
            if (adjacencyMatrix[i][j] == 1) {
                edgeList.emplace_back(i + 1, j + 1); // Chuyển từ chỉ số 0-based sang 1-based
            }
        }
    }

    // Ghi danh sách cạnh vào file
    string fileName = "testdothi.txt";
    WriteEdgeListToFile(n, edgeList, fileName);

    return 0;
}
