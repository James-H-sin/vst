/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
HelloWorldAudioProcessorEditor::HelloWorldAudioProcessorEditor (HelloWorldAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    myImage = juce::ImageCache::getFromMemory (BinaryData::IMG_3842_jpeg,BinaryData::IMG_3842_jpegSize);
}

HelloWorldAudioProcessorEditor::~HelloWorldAudioProcessorEditor()
{
}

//==============================================================================
void HelloWorldAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    
    const int xDest = 200;
       const int yDest = 100;
       auto transform = juce::AffineTransform::scale (0.05f, 0.05f)
           .translated (xDest, yDest)
           .rotated (
                     juce::MathConstants<float>::pi / 2.0f,
                     xDest,
                     yDest);  // rotate around center
       g.drawImageTransformed(myImage, transform);
}

void HelloWorldAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
