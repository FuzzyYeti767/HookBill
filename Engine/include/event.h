#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

namespace HookBill
{
    class Event {
    public:
        enum class Type {
            KeyPressed,
            KeyReleased,
            MouseMoved,
            MouseScroll,
            MouseButtonPressed,
            MouseButtonReleased
        };

        Event(Type type, int key = 0, double x = 0, double y = 0)
            : type(type), key(key), x(x), y(y) {
        }

        Type type;
        int key;      
        double x, y; 
    };

  
    class EventListener {
    public:
        using Callback = std::function<void(const Event&)>;

        EventListener(Event::Type type, Callback callback)
            : eventType(type), callback(callback) {
        }

        Event::Type getEventType() const { return eventType; }
        void handleEvent(const Event& event) const { callback(event); }

    private:
        Event::Type eventType;
        Callback callback;
    };

   
    class EventDispatcher {
    public:
   
        void addListener(const EventListener& listener) {
            listeners[listener.getEventType()].push_back(listener);
        }

       
        void dispatch(const Event& event) const {
            auto it = listeners.find(event.type);
            if (it != listeners.end()) {
                for (const auto& listener : it->second) {
                    listener.handleEvent(event);
                }
            }
        }

    private:
        std::unordered_map<Event::Type, std::vector<EventListener>> listeners;
    };
}


