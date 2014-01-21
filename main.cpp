/* 
 * File:   main.cpp
 * Author: roberto
 *
 * Created on January 21, 2014, 4:46 PM
 */
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    // Create the main window
    RenderWindow App(VideoMode(800, 600), "Ejemplo de sfml");
    // Load a sprite to display
    Image Image;
    if (!Image.LoadFromFile("cute_image.jpg"))
        return EXIT_FAILURE;
    Sprite Sprite(Image);
    // Create a graphical string to display
    Font Arial;
    if (!Arial.LoadFromFile("/usr/share/fonts/truetype/LiberationMono-Italic.ttf")){
        return EXIT_FAILURE;
    }
    String Text("Hello SFML", Arial, 50);
    // Load a music to play
    Music Music;
    if (!Music.OpenFromFile("nice_music.ogg")) {
        return EXIT_FAILURE;
    }
    // Play the music
    Music.Play();
    // Start the game loop
    // Bucle principal del juego
    bool Running = true;
    while (Running) {
        while (App.IsOpened()) {
            // Process events
            Event Event;
            while (App.GetEvent(Event)) {
                // Close window : exit
                if (Event.Type == Event::Closed){
                    Running = false;
                    App.Close();
                }
                
                // Escape key pressed
                if ((Event.Type == Event::KeyPressed) && (Event.Key.Code == Key::Escape)){
                    Running = false;
                    App.Close();
                }
            }
            // Clear screen
            App.Clear();
            // Draw the sprite
            App.Draw(Sprite);
            // Draw the string
            App.Draw(Text);
            // Update the window
            App.Display();
        }
    }
    return EXIT_SUCCESS;
}
