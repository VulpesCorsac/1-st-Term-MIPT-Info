#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

template <typename T>

class List
{
    struct Node
    {
    public:

        T m_data;

        Node *m_prev;
        Node *m_next;

        Node(const T &data)
        {
            m_prev = m_next = NULL;
            m_data = data;
        }
    };

public:

    Node *m_head;
    Node *m_tail;
    size_t m_size;

    List()
    {
        m_size = 0;
        m_head = m_tail = NULL;
    }

    List(const List &source)
    {
        m_head = m_tail = NULL;
        m_size = source.m_size;

        Node *i = source.m_head;

        while (i != NULL)
        {
            push_back(i->m_data);
            i = i->m_next;
        }
    }

    ~List()
    {
        clear();
    }

    size_t size()
    {
        return m_size;
    }

    bool is_empty()
    {
        return m_size == 0;
    }

    void clear()
    {
        while (!is_empty())
            pop_back();
    }

    void push_back(const T &data)
    {
        Node *add_elem = new Node (data);

        if (m_size == 0)
        {
            m_head = add_elem;
        }
        else
        {
            m_tail->m_next = add_elem;
            add_elem->m_prev = m_tail;
        }

        m_tail = add_elem;

        ++m_size;
    }

    T pop_back()
    {
        T ret_item = m_tail->m_data;

        Node *new_tail = m_head == m_tail ? NULL : m_tail->m_prev;

        delete m_tail;

        if (m_head == m_tail)
            m_head = NULL;

        m_tail = new_tail;

        --m_size;

        return ret_item;
    }

    void push_front(const T &data)
    {
        Node *add_item = new Node (data);

        if (m_size == 0)
        {
            m_tail = add_item;
        }
        else
        {
            m_head->m_prev = add_item;
            add_item->m_next = m_head;
        }

        m_head = add_item;

        ++m_size;
    }

    T pop_front()
    {
        T ret_item = m_head->m_data;
        Node *new_head = m_head == m_tail ? NULL : m_head->m_next;

        delete m_head;

        if (m_head == m_tail)
            m_tail = 0;

        m_head = new_head;

        --m_size;

        return ret_item;
    }

    int count(const T &data)
    {
        Node *temp;
        int count = 0;

        for (temp = m_head; temp; temp = temp->m_next)
            if (temp->m_data == data)
                count++;

        return count;
    }

    bool erase(const T &data)
    {
        Node *temp;

        for (temp = m_head; temp; temp = temp->m_next)
            if (temp->m_data == data)
            {
                if (temp == m_head)
                    m_head = temp->m_next;
                if (temp == m_tail)
                    m_tail = temp->m_prev;

                Node *n_prev = temp->m_prev;
                Node *n_next = temp->m_next;

                if (n_prev)
                    n_prev->m_next = n_next;
                if (n_next)
                    n_next->m_prev = n_prev;

                delete temp;

                m_size--;

                return true;
            }

            return false;
    }

    int all_erase(const T &data)
    {
        int count = 0;

        while (erase(data))
            count++;

        return count;
    }
};

struct address
{
    int x, y;
};

struct square
{
    bool visited;
    bool free;
    address addr;
};

int main()
{
    int n, m;
    vector < vector < square > > table;

    cin >> n >> m;
    table.resize(n);
    for (int i = 0; i < n; i++)
    {
        table[i].resize(m);
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '.')
                table[i][j].free = true;
            else
                table[i][j].free = false;
        }
    }

    address temp, temp1;
    temp.x = temp.y = 0;

    List < address > list;

    list.push_back(temp);
    table[0][0].visited = true;

    while (list.size())
    {
        temp = list.pop_front();
//        cout << temp.x << " " << temp.y << endl;

        temp1.x = temp.x + 1;
        temp1.y = temp.y;
        if (temp1.x < n && table[temp1.x][temp1.y].visited == false && table[temp1.x][temp1.y].free == true)
        {
            table[temp1.x][temp1.y].addr = temp;
            table[temp1.x][temp1.y].visited = true;
            list.push_back(temp1);
        }

        temp1.x = temp.x - 1;
        temp1.y = temp.y;
        if (temp1.x >= 0 && table[temp1.x][temp1.y].visited == false && table[temp1.x][temp1.y].free == true)
        {
            table[temp1.x][temp1.y].addr = temp;
            table[temp1.x][temp1.y].visited = true;
            list.push_back(temp1);
        }

        temp1.x = temp.x;
        temp1.y = temp.y + 1;
        if (temp1.y < m && table[temp1.x][temp1.y].visited == false && table[temp1.x][temp1.y].free == true)
        {
            table[temp1.x][temp1.y].addr = temp;
            table[temp1.x][temp1.y].visited = true;
            list.push_back(temp1);
        }

        temp1.x = temp.x;
        temp1.y = temp.y - 1;
        if (temp1.y >= 0 && table[temp1.x][temp1.y].visited == false && table[temp1.x][temp1.y].free == true)
        {
            table[temp1.x][temp1.y].addr = temp;
            table[temp1.x][temp1.y].visited = true;
            list.push_back(temp1);
        }
    }

    if (table[n - 1][m - 1].visited == false)
    {
        cout << "NO";
        return 0;
    }

    temp.x = n - 1;
    temp.y = m - 1;
    while (temp.x + temp.y)
    {
        cout << temp.x << " " << temp.y << endl;
        temp = table[temp.x][temp.y].addr;
    }
    cout << "0 0" << endl;

    return 0;
}
