/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainPlugin2AudioProcessorEditor::GainPlugin2AudioProcessorEditor (GainPlugin2AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    
    setSize (400, 300);
    mGainControlSlider.setBounds(0, 0, 100, 100);
    mGainControlSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mGainControlSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    mGainControlSlider.setRange(gainParameter->range.start, gainParameter->range.end);
    mGainControlSlider.setValue(*gainParameter);

    addAndMakeVisible(mGainControlSlider);
    
    auto& params = processor.getParameters();
    juce::AudioParameterFloat* gainParameter = (juce::AudioParameterFloat*)params.getUnchecked(0);
    
    mGainControlSlider.onValueChange = [this, gainParameter] {
    *gainParameter = mGainControlSlider.getValue();
    };
    
    mGainControlSlider.onDragStart = [gainParameter] {
            gainParameter->beginChangeGesture();
        };
        
        mGainControlSlider.onValueChange = [this, gainParameter] {
        *gainParameter = mGainControlSlider.getValue();
        };
        
        mGainControlSlider.onDragEnd = [gainParameter] {
            gainParameter->endChangeGesture();
        };
}

GainPlugin2AudioProcessorEditor::~GainPlugin2AudioProcessorEditor()
{
}

//==============================================================================
void GainPlugin2AudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void GainPlugin2AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
