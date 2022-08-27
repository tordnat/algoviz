#include <SDL.h>
#include <iostream>
#include <random>
#include <ranges>
#include <algorithm>
#include "visualizer_lib.h"
#include "beep.h"

#define WINDOW_SCALE 5
#define FREQ_SCALER 40
#define FREQ_OFFSET 1400
#define N 100
#define N_RANGE 100
#define AUDIO false

void draw_state(
    std::vector<int>& v,
    SDL_Renderer* renderer,
    unsigned int red,
    unsigned int blue)
{
    int index = 0;
    for (int i : v){
        if (index == red)
        SDL_SetRenderDrawColor(renderer, 255,0,0,255);
        else if (index == blue) 
        SDL_SetRenderDrawColor(renderer, 0,0,255,255);
        else SDL_SetRenderDrawColor(renderer, 255,255,255,255);
        SDL_RenderDrawLine(renderer, index, 99, index, i);
        index +=1;
    }    
}

int algorithm_visualizer(){
    std::random_device rd;
    std::uniform_int_distribution<int> d(1,N_RANGE-1);
    std::vector<int> v;
    bool quit = false;
    SDL_Event e;
    
    //Populate vector v with random numbers
    for(int i = 0; i < N; i++){
        v.push_back(d(rd));
    }
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(100*WINDOW_SCALE, 100*WINDOW_SCALE, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 1*WINDOW_SCALE, 1*WINDOW_SCALE);
    SDL_Init(SDL_INIT_AUDIO);
    // Sort algorithm

    while (!quit){
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                quit = true;
            }
            for(unsigned int i = 0; i < v.size(); i++){
        for(unsigned int j = i; j < v.size(); j++){
            if(v[j] < v[i]){
                std::swap(v[j], v[i]);
            }          
            // Clear screen
            SDL_SetRenderDrawColor(renderer,0,0,0,255);
            SDL_RenderClear(renderer);

            // Draw state of sort
            //  
            draw_state(v, renderer, i, j);

            //Show to window
            //
            #if AUDIO
            beep_f((N_RANGE - v[j])*FREQ_SCALER+FREQ_OFFSET, RENDER_DELAY);
            #endif
            SDL_RenderPresent(renderer);
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
        }
    }
    

    for(int i : v){
        std::cout << i << " ";
    }

    //check if sorted

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
