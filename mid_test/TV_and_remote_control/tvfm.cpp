#include "tvfm.h"
#include <iostream>
using std::cout;
using std::endl;

bool Tv::On = true, Tv::Off = false;
Tv::Tv() : maxchannel(125), maxvolume(20), minvolume(0) {
    chan_ = 5;
    state_ = false;
    mode_ = 5;
    input_ = 2;
    volume_ = 0;
}
Tv::Tv(bool tmp) : maxchannel(125), maxvolume(20), minvolume(0) {
    chan_ = 1;
    state_ = tmp;
    mode_ = 5;
    input_ = 2;
    volume_ = 5;
}
void Tv::settings() {
    if (state_) {
        cout << "TV is On" << endl;
        cout << "Volume setting = " << volume_ << endl;
        cout << "Channel setting = " << chan_ << endl;
        cout << "Mode = " << (mode_ == 5 ? "cable" : "antenna") << endl;
        cout << "Input = " << (input_ == 2 ? "TV" : "DVD") << endl;
    } else {
        cout << "TV is Off" << endl;
    }
}
void Tv::onoff() {
    if (state_) state_ = Off;
    else state_ = On;
}
void Tv::chanup() {
    if (chan_ == maxchannel) chan_ = 1;
    else ++chan_;
}
void Tv::chandown() {
    if (chan_ == 1) chan_ = maxchannel;
    else --chan_;
}
void Tv::volup() {
    if (volume_ < maxvolume) ++volume_;
}
void Tv::voldown() {
    if (volume_ > minvolume) --volume_;
}
void Tv::set_mode() {
    mode_ == 5 ? mode_ = 4 : mode_ = 5;
}
void Tv::set_input() {
    input_ == 2 ? input_ = 3 : input_ = 2;
}
Remote::Remote() : Tv() {}
void Remote::chanup(Tv& x) const {
    if (x.chan_ < x.maxchannel) ++(x.chan_);
}
void Remote::chandown(Tv& x) const {
    if (x.chan_ > 1) --(x.chan_);
}
void Remote::volup(Tv& x) const {
    if (x.volume_ < x.maxvolume) ++(x.volume_);
}
void Remote::voldown(Tv& x) const {
    if (x.volume_ > x.minvolume) --(x.volume_);
}
void Remote::set_mode(Tv& x) const {
    x.mode_ == 5 ? x.mode_ = 4 : x.mode_ = 5;
}
void Remote::set_input(Tv& x) const {
    x.input_ == 2 ? x.input_ = 3 : x.input_ = 2;
}
void Remote::set_chan(Tv& x, int chan) const {
    if (chan >= 1 && chan <= x.maxchannel) {
        x.chan_ = chan;
    }
}
