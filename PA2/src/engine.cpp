
#include "engine.h"

Engine::Engine(string name, int width, int height)
{
  m_WINDOW_NAME = name;
  m_WINDOW_WIDTH = width;
  m_WINDOW_HEIGHT = height;
  m_FULLSCREEN = false;
}

Engine::Engine(string name)
{
  m_WINDOW_NAME = name;
  m_WINDOW_HEIGHT = 0;
  m_WINDOW_WIDTH = 0;
  m_FULLSCREEN = true;
}

Engine::~Engine()
{
  delete m_window;
  delete m_graphics;
  m_window = NULL;
  m_graphics = NULL;
}

bool Engine::Initialize()
{
  // Start a window
  m_window = new Window();
  if(!m_window->Initialize(m_WINDOW_NAME, &m_WINDOW_WIDTH, &m_WINDOW_HEIGHT))
  {
    printf("The window failed to initialize.\n");
    return false;
  }

  // Start the graphics
  m_graphics = new Graphics();
  if(!m_graphics->Initialize(m_WINDOW_WIDTH, m_WINDOW_HEIGHT))
  {
    printf("The graphics failed to initialize.\n");
    return false;
  }

  // Set the time
  m_currentTimeMillis = GetCurrentTimeMillis();

  // No errors
  return true;
}

void Engine::Run()
{
  m_running = true;

  while(m_running)
  {
    // Update the DT
    m_DT = getDT();

    // Check the keyboard input
    while(SDL_PollEvent(&m_event) != 0)
    {
     Keyboard();
    }

    // Update and render the graphics
    m_graphics->Update(m_DT, keyInput);
    m_graphics->Render();

    // Swap to the Window
    m_window->Swap();
  }
}

void Engine::Keyboard()
{
  if(m_event.type == SDL_QUIT)
  {
    m_running = false;

  }
  else if (m_event.type == SDL_KEYDOWN)
  {
    // handle key down events here
    if (m_event.key.keysym.sym == SDLK_ESCAPE)
    {
      m_running = false;
    
    }
    else if (m_event.key.keysym.sym == SDLK_w)
    {
    keyInput = SDLK_w; // Toggle Translate (Angle) start
    }
    else if (m_event.key.keysym.sym == SDLK_q)
    {
    keyInput = SDLK_q; // Toggle Translate (Angle) stop
    }
    else if (m_event.key.keysym.sym == SDLK_e)
    {
    keyInput = SDLK_e; // Toggle Translate (Angle) stop
    }
    else if (m_event.key.keysym.sym == SDLK_s)
    {
    keyInput = SDLK_s; // Rotate (Spin) Start
    }
    else if (m_event.key.keysym.sym == SDLK_a)
    {
    keyInput = SDLK_a; // Rotate (Spin) Stop
    }
    else if (m_event.key.keysym.sym == SDLK_d)
    {
    keyInput = SDLK_d; // Rotate (Spin) Stop
    }    
    else if (m_event.key.keysym.sym == SDLK_SPACE)
    {
    keyInput = SDLK_SPACE; // Toggle Pause
    }
    else if (m_event.key.keysym.sym == SDLK_c)
    {
    keyInput = SDLK_c; // Toggle Continue
    }
    else if (m_event.key.keysym.sym == SDLK_o)
    {
    keyInput = SDLK_o; // Toggle Translate (Angle) start
    }
    else if (m_event.key.keysym.sym == SDLK_s)
    {
    keyInput = SDLK_s; // Toggle Translate (Angle) start
    }
    else if (m_event.key.keysym.sym == SDLK_x)
    {
    keyInput = SDLK_x; // Toggle Translate (Angle) start
    }
    else if (m_event.key.keysym.sym == SDLK_z)
    {
    keyInput = SDLK_z; // Toggle Translate (Angle) start
    }
    else if (m_event.key.keysym.sym == SDLK_0)
    {
    keyInput = SDLK_0; // Toggle Camera state 0
    }
    else if (m_event.key.keysym.sym == SDLK_1)
    {
    keyInput = SDLK_1; // Toggle Camera state 1
    }
    else if (m_event.key.keysym.sym == SDLK_2)
    {
    keyInput = SDLK_2; // Toggle Camera state 0
    }
    else if (m_event.key.keysym.sym == SDLK_3)
    {
    keyInput = SDLK_3; // Toggle Camera state 1
    }
    else if (m_event.key.keysym.sym == SDLK_4)
    {
    keyInput = SDLK_4; // Toggle Camera state 1
    }
    else if (m_event.key.keysym.sym == SDLK_UP)
    {
    keyInput = SDLK_UP; // Toggle Camera state 1
    }
    else if (m_event.key.keysym.sym == SDLK_DOWN)
    {
    keyInput = SDLK_DOWN; // Toggle Camera state 1
    }
    else if (m_event.key.keysym.sym == SDLK_LEFT)
    {
    keyInput = SDLK_LEFT; // Toggle Camera state 1
    }
    else if (m_event.key.keysym.sym == SDLK_RIGHT)
    {
    keyInput = SDLK_RIGHT; // Toggle Camera state 1
    }

    /*
    else if (m_event.key.keysym.sym == SDLK_m)
    {
    keyInput = SDLK_m; // Toggle Camera state 1
    }
    else if (m_event.key.keysym.sym == SDLK_n)
    {
    keyInput = SDLK_n; // Toggle Camera state 1
    }
    */
    // else if ()

  }

}

unsigned int Engine::getDT()
{
  long long TimeNowMillis = GetCurrentTimeMillis();
  assert(TimeNowMillis >= m_currentTimeMillis);
  unsigned int DeltaTimeMillis = (unsigned int)(TimeNowMillis - m_currentTimeMillis);
  m_currentTimeMillis = TimeNowMillis;
  return DeltaTimeMillis;
}

long long Engine::GetCurrentTimeMillis()
{
  timeval t;
  gettimeofday(&t, NULL);
  long long ret = t.tv_sec * 1000 + t.tv_usec / 1000;
  return ret;
}
