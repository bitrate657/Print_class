class Print {
public:
    Print(const bool is_cout) : is_cout(is_cout) {} // trueならcout falseならcerr

    //要素数を省略した場合は全部出力
    template<typename T>
    void pvec(const T &vec) {
        size_t sz = vec.size();
        if (is_cout) {
            for (size_t i = 0; i < sz; ++i)
                cout << vec[i] << (i == sz - 1 ? term : sep);
            flush(cout);
        }
        else {
            for (size_t i = 0; i < sz; ++i)
                cerr << vec[i] << (i == sz - 1 ? term : sep);
            flush(cerr);
        }
    }

    template<typename T>
    void pvec(const T &vec, size_t sz) {
        if (is_cout) {
            for (size_t i = 0; i < sz; ++i)
                cout << vec[i] << (i == sz - 1 ? term : sep);
            flush(cout);
        }
        else {
            for (size_t i = 0; i < sz; ++i)
                cerr << vec[i] << (i == sz - 1 ? term : sep);
            flush(cerr);
        }
    }

    template<typename T>
    void pmat(const T &mat) {
        size_t h = mat.size();
        size_t w = mat[0].size();//mat.size() > 0 を仮定
        if (is_cout) {
            for (size_t i = 0; i < h; ++i)
                for (size_t j = 0; j < w; ++j)
                    cout << mat[i][j] << (j == w - 1 ? term : sep);
            flush(cout);
        }
        else {
            for (size_t i = 0; i < h; ++i)
                for (size_t j = 0; j < w; ++j)
                    cerr << mat[i][j] << (j == w - 1 ? term : sep);
            flush(cerr);
        }
    }

    template<typename T>
    void pmat(const T &mat, size_t h, size_t w) {
        if (is_cout) {
            for (size_t i = 0; i < h; ++i)
                for (size_t j = 0; j < w; ++j)
                    cout << mat[i][j] << (j == w - 1 ? term : sep);
            flush(cout);
        }
        else {
            for (size_t i = 0; i < h; ++i)
                for (size_t j = 0; j < w; ++j)
                    cerr << mat[i][j] << (j == w - 1 ? term : sep);
            flush(cerr);
        }
    }

    template<typename... Args>
    void operator()(Args... args) const {
        print(args...);
        if (is_cout)
            flush(cout);
        else
            flush(cerr);
    }

private:
    bool is_cout;
    string sep = " ";
    string term = "\n";

    template<typename Head, typename... Tail>
    void print(Head &&head, Tail &&... tail) const {
        if (is_cout)
            cout << head;
        else
            cerr << head;
        print2(forward<Tail>(tail)...);
    }

    template<typename Head, typename...Tail>
    void print2(Head &&head, Tail &&... tail) const {
        if (is_cout)
            cout << sep << head;
        else
            cerr << sep << head;
        print2(forward<Tail>(tail)...);
    }

    void print2() const {
        if (is_cout)
            cout << term;
        else
            cerr << term;
    }
};
