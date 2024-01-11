const videos = [
    {
        title: "Talking Tech and AI with Google CEO Sundar Pichai!",
        author: "Marques Brownlee",
        time: "14:20",
        stats: {
            views: "3.4M",
            dateUploaded: "6 months ago"
        },
        images: {
            thumbnail: "thumbnail-1.webp",
            channelPicture: "channel-1.jpeg"
        }
    },
    {
        title: "Try Not To Laugh Challenge #9",
        author: "Markiplier",
        time: "8:22",
        stats: {
            views: "19M",
            dateUploaded: "4 years ago"
        },
        images: {
            thumbnail: "thumbnail-2.webp",
            channelPicture: "channel-2.jpeg"
        }
    },
    {
        title: "Crazy Tik Toks Taken Moments Before DISASTER",
        author: "SSSniperWolf",
        time: "9:13",
        stats: {
            views: "12M",
            dateUploaded: "1 year ago"
        },
        images: {
            thumbnail: "thumbnail-3.webp",
            channelPicture: "channel-3.jpeg"
        }
    },
    {
        title: "The Simplest Math Problem No One Can Solve - Collatz Conjecture",
        author: "Veritasium",
        time: "22:09",
        stats: {
            views: "18M",
            dateUploaded: "4 months ago"
        },
        images: {
            thumbnail: "thumbnail-4.webp",
            channelPicture: "channel-4.jpeg"
        }
    },
    {
        title: "Kadane's Algorithm to Maximum Sum Subarray Problem",
        author: "CS Dojo",
        time: "11:17",
        stats: {
            views: "519K",
            dateUploaded: "5 years ago"
        },
        images: {
            thumbnail: "thumbnail-5.webp",
            channelPicture: "channel-5.jpeg"
        }
    },
    {
        title: "Anything You Can Fit In The Circle I'll Pay For",
        author: "MrBeast",
        time: "19:59",
        stats: {
            views: "141M",
            dateUploaded: "1 year ago"
        },
        images: {
            thumbnail: "thumbnail-6.webp",
            channelPicture: "channel-6.jpeg"
        }
    },
    {
        title: "Why Planes Don't Fly Over Tibet",
        author: "RealLifeLore",
        time: "10:13",
        stats: {
            views: "6.6M",
            dateUploaded: "1 year ago"
        },
        images: {
            thumbnail: "thumbnail-7.webp",
            channelPicture: "channel-7.jpeg"
        }
    },
    {
        title: "Inside The World's Biggest Passenger Plane",
        author: "Tech Vision",
        time: "7:12",
        stats: {
            views: "3.7M",
            dateUploaded: "10 months ago"
        },
        images: {
            thumbnail: "thumbnail-8.webp",
            channelPicture: "channel-8.jpeg"
        }
    },
    {
        title: "The SECRET to Super Human STRENGTH",
        author: "ThenX",
        time: "13:17",
        stats: {
            views: "20M",
            dateUploaded: "3 years ago"
        },
        images: {
            thumbnail: "thumbnail-9.webp",
            channelPicture: "channel-9.jpeg"
        }
    },
    {
        title: "How The World's Largest Cruise Ship Makes 30,000 Meals Every Day",
        author: "Business Insider",
        time: "7:53",
        stats: {
            views: "14M",
            dateUploaded: "1 year ago"
        },
        images: {
            thumbnail: "thumbnail-10.webp",
            channelPicture: "channel-10.jpeg"
        }
    },
    {
        title: "Dubai's Crazy Underwater Train and Other Things #Only in Dubai",
        author: "Destination Tips",
        time: "4:10",
        stats: {
            views: "3M",
            dateUploaded: "1 year ago"
        },
        images: {
            thumbnail: "thumbnail-11.webp",
            channelPicture: "channel-11.jpeg"
        }
    },
    {
        title: "What would happen if you didn't drink water? - Mia Nacamulli",
        author: "TED-Ed",
        time: "4:51",
        stats: {
            views: "12M",
            dateUploaded: "5 years ago"
        },
        images: {
            thumbnail: "thumbnail-12.webp",
            channelPicture: "channel-12.jpeg"
        }
    },
]

function displayVideoGrid() {
    let videoGridHTML = "";
    videos.forEach((video) => {
        videoGridHTML += `
        <div class="video-preview">
        <div class="thumbnail-row">
          <img class="thumbnail" src="thumbnails/${video.images.thumbnail}">
          <div class="video-time">${video.time}</div>
        </div>
        <div class="video-info-grid">
          <div class="channel-picture">
            <img class="profile-picture" src="channel-pictures/${video.images.channelPicture}">
          </div>
          <div class="video-info">
            <p class="video-title">
              ${video.title}
            </p>
            <p class="video-author">
              ${video.author}
            </p>
            <p class="video-stats">
              ${video.stats.views} views &#183; ${video.stats.dateUploaded} 
            </p>
          </div>
        </div>
      </div>
      `
    });

    const videoGridElement = document.querySelector(".video-grid");
    videoGridElement.innerHTML = videoGridHTML;
}

displayVideoGrid();