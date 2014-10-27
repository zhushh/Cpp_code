#ifndef TVFM_H
#define TVFM_H

class Tv {
    friend class Remote;
    public:
        Tv();
        explicit Tv(bool tmp);
        void settings();
        void onoff();
        void chanup();
        void chandown();
        void volup();
        void voldown();
        void set_mode();
        void set_input();
        static bool On, Off;
    private:
        bool state_;
        int chan_;
        int volume_;
        int mode_;
        int input_;
        const int maxchannel;
        const int maxvolume;
        const int minvolume;
};

class Remote : public Tv {
    public:
        Remote();
        void chanup(Tv& x) const;
        void chandown(Tv& x) const;
        void volup(Tv& x) const;
        void voldown(Tv& x) const;
        void set_mode(Tv& x) const;
        void set_input(Tv& x) const;
        void set_chan(Tv& x, int chan) const;
};

#endif
