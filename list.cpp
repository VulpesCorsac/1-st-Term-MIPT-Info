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
