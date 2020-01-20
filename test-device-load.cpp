#include <mediasoupclient.hpp>
#include <iostream>

int main() {
    mediasoupclient::Initialize();

    auto rtpCaps = R"({
    "codecs": [{
        "kind": "audio",
        "mimeType": "audio/opus",
        "clockRate": 48000,
        "channels": 2,
        "rtcpFeedback": [{
            "type": "transport-cc"
        }],
        "preferredPayloadType": 100,
        "parameters": {}
    }, {
        "kind": "video",
        "mimeType": "video/VP8",
        "clockRate": 90000,
        "rtcpFeedback": [{
            "type": "nack"
        }, {
            "type": "nack",
            "parameter": "pli"
        }, {
            "type": "ccm",
            "parameter": "fir"
        }, {
            "type": "goog-remb"
        }, {
            "type": "transport-cc"
        }],
        "preferredPayloadType": 101,
        "parameters": {
            "x-google-start-bitrate": 1000
        }
    }, {
        "kind": "video",
        "mimeType": "video/rtx",
        "preferredPayloadType": 102,
        "clockRate": 90000,
        "rtcpFeedback": [],
        "parameters": {
            "apt": 101
        }
    }, {
        "kind": "video",
        "mimeType": "video/VP9",
        "clockRate": 90000,
        "rtcpFeedback": [{
            "type": "nack"
        }, {
            "type": "nack",
            "parameter": "pli"
        }, {
            "type": "ccm",
            "parameter": "fir"
        }, {
            "type": "goog-remb"
        }, {
            "type": "transport-cc"
        }],
        "preferredPayloadType": 103,
        "parameters": {
            "profile-id": 2,
            "x-google-start-bitrate": 1000
        }
    }, {
        "kind": "video",
        "mimeType": "video/rtx",
        "preferredPayloadType": 104,
        "clockRate": 90000,
        "rtcpFeedback": [],
        "parameters": {
            "apt": 103
        }
    }, {
        "kind": "video",
        "mimeType": "video/H264",
        "clockRate": 90000,
        "parameters": {
            "packetization-mode": 1,
            "level-asymmetry-allowed": 1,
            "profile-level-id": "4d0032",
            "x-google-start-bitrate": 1000
        },
        "rtcpFeedback": [{
            "type": "nack"
        }, {
            "type": "nack",
            "parameter": "pli"
        }, {
            "type": "ccm",
            "parameter": "fir"
        }, {
            "type": "goog-remb"
        }, {
            "type": "transport-cc"
        }],
        "preferredPayloadType": 105
    }, {
        "kind": "video",
        "mimeType": "video/rtx",
        "preferredPayloadType": 106,
        "clockRate": 90000,
        "rtcpFeedback": [],
        "parameters": {
            "apt": 105
        }
    }, {
        "kind": "video",
        "mimeType": "video/H264",
        "clockRate": 90000,
        "parameters": {
            "packetization-mode": 1,
            "level-asymmetry-allowed": 1,
            "profile-level-id": "42e01f",
            "x-google-start-bitrate": 1000
        },
        "rtcpFeedback": [{
            "type": "nack"
        }, {
            "type": "nack",
            "parameter": "pli"
        }, {
            "type": "ccm",
            "parameter": "fir"
        }, {
            "type": "goog-remb"
        }, {
            "type": "transport-cc"
        }],
        "preferredPayloadType": 107
    }, {
        "kind": "video",
        "mimeType": "video/rtx",
        "preferredPayloadType": 108,
        "clockRate": 90000,
        "rtcpFeedback": [],
        "parameters": {
            "apt": 107
        }
    }],
    "headerExtensions": [{
        "kind": "audio",
        "uri": "urn:ietf:params:rtp-hdrext:sdes:mid",
        "preferredId": 1,
        "preferredEncrypt": false,
        "direction": "recvonly"
    }, {
        "kind": "video",
        "uri": "urn:ietf:params:rtp-hdrext:sdes:mid",
        "preferredId": 1,
        "preferredEncrypt": false,
        "direction": "recvonly"
    }, {
        "kind": "video",
        "uri": "urn:ietf:params:rtp-hdrext:sdes:rtp-stream-id",
        "preferredId": 2,
        "preferredEncrypt": false,
        "direction": "recvonly"
    }, {
        "kind": "video",
        "uri": "urn:ietf:params:rtp-hdrext:sdes:repaired-rtp-stream-id",
        "preferredId": 3,
        "preferredEncrypt": false,
        "direction": "recvonly"
    }, {
        "kind": "audio",
        "uri": "http://www.webrtc.org/experiments/rtp-hdrext/abs-send-time",
        "preferredId": 4,
        "preferredEncrypt": false,
        "direction": "sendrecv"
    }, {
        "kind": "video",
        "uri": "http://www.webrtc.org/experiments/rtp-hdrext/abs-send-time",
        "preferredId": 4,
        "preferredEncrypt": false,
        "direction": "sendrecv"
    }, {
        "kind": "audio",
        "uri": "http://www.ietf.org/id/draft-holmer-rmcat-transport-wide-cc-extensions-01",
        "preferredId": 5,
        "preferredEncrypt": false,
        "direction": "recvonly"
    }, {
        "kind": "video",
        "uri": "http://www.ietf.org/id/draft-holmer-rmcat-transport-wide-cc-extensions-01",
        "preferredId": 5,
        "preferredEncrypt": false,
        "direction": "sendrecv"
    }, {
        "kind": "video",
        "uri": "http://tools.ietf.org/html/draft-ietf-avtext-framemarking-07",
        "preferredId": 6,
        "preferredEncrypt": false,
        "direction": "sendrecv"
    }, {
        "kind": "video",
        "uri": "urn:ietf:params:rtp-hdrext:framemarking",
        "preferredId": 7,
        "preferredEncrypt": false,
        "direction": "sendrecv"
    }, {
        "kind": "audio",
        "uri": "urn:ietf:params:rtp-hdrext:ssrc-audio-level",
        "preferredId": 10,
        "preferredEncrypt": false,
        "direction": "sendrecv"
    }, {
        "kind": "video",
        "uri": "urn:3gpp:video-orientation",
        "preferredId": 11,
        "preferredEncrypt": false,
        "direction": "sendrecv"
    }, {
        "kind": "video",
        "uri": "urn:ietf:params:rtp-hdrext:toffset",
        "preferredId": 12,
        "preferredEncrypt": false,
        "direction": "sendrecv"
    }],
    "fecMechanisms": []
})"_json;

    mediasoupclient::Device* d = new mediasoupclient::Device();
    d->Load(rtpCaps);

    std::cout << d->GetRtpCapabilities() << std::endl;
}