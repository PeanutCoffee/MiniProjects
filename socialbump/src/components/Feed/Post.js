import { Avatar } from '@mui/material'
import React from 'react'
import ThumbUpOffAltIcon from '@mui/icons-material/ThumbUpOffAlt';
import ChatBubbleOutlineIcon from '@mui/icons-material/ChatBubbleOutline';
import ShareOutlinedIcon from '@mui/icons-material/ShareOutlined';
import MoreHorizIcon from '@mui/icons-material/MoreHoriz';
import './style.css'
const Post = ({  name, profilePic, timestamp, message, image }) => {
    return (
        <div className='createPost'>
            <div className='post'>

                {/* post-top */}
                <div className='post-top'>
                    <div className='post-topLeft'>
                        <Avatar
                            src={profilePic}
                        />
                        <div className='postInfo'>
                            <h4>
                                {name}
                            </h4>
                            <p>
                                {new Date(timestamp?.toDate()).toUTCString()}
                            </p>
                        </div>
                    </div>
                    <MoreHorizIcon className='postInfo-option'/>
                </div>

                {/* post-center */}
                <div className='post-center'>
                    <p>
                        {message}
                    </p>
                    {image
                        &&
                        <img src={image} />
                    }
                </div>

                {/* post-bottom */}
                <div className='post-bottom'>
                    <div className='post-option'>
                        <ThumbUpOffAltIcon /> <p>Like</p>
                    </div>
                    <div className='post-option'>
                        <ChatBubbleOutlineIcon /> <p>Comment</p>
                    </div>
                    <div className='post-option'>
                        <ShareOutlinedIcon /> <p>Share</p>
                    </div>
                </div>
            </div>
        </div>
    )
}

export default Post
