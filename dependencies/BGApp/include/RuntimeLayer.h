#pragma once
#include <vector>

class RuntimeLayer {
public:
    virtual ~RuntimeLayer() = default;

    virtual void Start();
    virtual void Update();
    virtual void Shutdown();
};

class RuntimeLayerStack {
public:
    ~RuntimeLayerStack() {
        for (RuntimeLayer* layer : _runtimeLayers) {
            layer->Shutdown();
            delete layer;
        }
    }

    void AddLayer(RuntimeLayer* layer) {
        _runtimeLayers.push_back(layer);
    }

    void RemoveLayer(RuntimeLayer* layer) {
        _runtimeLayers.erase(std::find(_runtimeLayers.begin(), _runtimeLayers.end(), layer));
    }

    std::vector<RuntimeLayer*>::iterator begin() { return _runtimeLayers.begin(); }
    std::vector<RuntimeLayer*>::iterator end() { return _runtimeLayers.end(); }
    std::vector<RuntimeLayer*>::const_iterator begin() const { return _runtimeLayers.begin(); }
    std::vector<RuntimeLayer*>::const_iterator end() const { return _runtimeLayers.end(); }
private:
    std::vector<RuntimeLayer*> _runtimeLayers;
};
