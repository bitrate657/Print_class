# Print_class
C++の競プロ用printクラスです。scolさんのhttps://scol.hatenablog.com/entry/2020/09/14/215726
を参考に作成しました。  
scolさんのものとの差異  
・sepとtermを実行時に選択できる機能を削除  
・vectorや2次元vectorを出力するときに要素数を指定しなかった場合はすべて出力するように  
・コンストラクタ呼び出し時に標準出力と標準エラー出力のどちらに出力するか選択できるように

このプログラムは MIT License のもとで公開されています。
ただし、競技プログラミングのためにこのプログラムの一部をジャッジサーバなどに送信するとき、
著作権表示および許諾表示を省略することができます。

使用例
```cpp
// include は省略
using namespace std; // 前提 

//ここにmain.hppの中身

Print print(true); // trueを選択すると標準出力
Print debug(false); // falseを選択すると標準エラー出力

int main() {
    // 1 abc a
    print(1, "abc", 'a'); // 標準出力
    debug(1, "abc", 'a'); // 標準エラー出力
    
    vector<int> vec(3);
    // 0 0 0
    print.pvec(vec);
    // 0 0
    print.pvec(vec, 2); // 第2引数に要素数を指定するとその要素数ぶんだけ出力
    
    vector<vector<int>> mat(3, vector<int>> (3));
    // 0 0 0
    // 0 0 0
    // 0 0 0
    print.pmat(mat);
    // 0
    // 0
    print.pmat(mat, 2, 1); // 第2、第3引数に要素数を指定するとその要素数ぶんだけ出力
}
```

