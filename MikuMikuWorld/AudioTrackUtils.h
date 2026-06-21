#pragma once
#include "Audio/Sound.h"
#include "Score.h"
#include "Utilities.h"
#include <string>

namespace MikuMikuWorld
{
	struct ScoreContext;
}

namespace MikuMikuWorld::AudioTrackUtils
{
	struct RenderedAudio
	{
		Audio::SoundBuffer buffer;
		float timelineStartMs = 0.0f;
	};

	void ensureDefaultAudioTrack(Score& score, const std::string& sourceFile,
	                             float timelineStartMs, float sourceLengthMs);
	bool hasAudioTrackData(const Score& score);
	bool hasAudioTrackEdits(const Score& score);
	float getRenderedTimelineStartMs(const Score& score, float fallbackMusicOffsetMs,
	                                 bool ignoreEditorMute = false);
	Result renderToBuffer(const Score& score, const std::string& fallbackSourceFile,
	                      RenderedAudio& output, bool ignoreEditorMute = false);
	Result refreshPlaybackAudio(MikuMikuWorld::ScoreContext& context);
	void syncMusicOffsetFromAudioTrack(MikuMikuWorld::ScoreContext& context);
	Result exportEditedAudio(const Score& score, const std::string& fallbackSourceFile,
	                         const std::string& outputDirectory, std::string& outputFilename);
}
