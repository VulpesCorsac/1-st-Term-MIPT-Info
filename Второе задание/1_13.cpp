bool check(AvlTree T, int &h) {
    if (!T) {
        h = 0;
        return true;
    }
    int h1, h2;
    if (!(check(T->Left, h1) && check(T->Right, h2))) {
        h = max(h1, h2) + 1;
        return false;
    }
    h = max (h1, h2) + 1;
    if (abs(h1 - h2) > 1)
        return false;
    return true;
}