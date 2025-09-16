#include <ncurses.h>

class ConsoleViewport;
class SidePanel;

class GameOverScreen {
public:
    GameOverScreen(const ConsoleViewport& viewport, const SidePanel& statistic);
    ~GameOverScreen();
    void render();
private:
    class StatisticWindow {
    public:
        StatisticWindow(int height, int width, WINDOW* parent, const SidePanel& statistic);
        ~StatisticWindow();
        void render();
        // Getters
        //int width() const;
    private:
        int height_;
        int width_;
        int score_;
        int level_;
        WINDOW* win_;
    };
    class MenuWindow {
    public:
        MenuWindow(int height, int width, WINDOW* parent);
        ~MenuWindow();
        void render();
    private:
        int height_;
        int width_;
        WINDOW* win_;
    };
    int height_;
    int width_;
    WINDOW* gameOverWin_;
    StatisticWindow statisticWin_;
    MenuWindow menuWin_;
};